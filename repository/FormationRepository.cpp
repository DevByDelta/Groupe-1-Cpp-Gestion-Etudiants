#include "FormationRepository.hpp"
#include <fstream>
#include <sstream>
#include <map>
#include <dirent.h>
#include <cstdio>
#include <cstring>

bool FormationRepository::save(const Formation& obj) {
    std::ofstream ofs(FORMATION_FILE(obj.getId()));
    if (!ofs.is_open()) return false;
    ofs << obj.toTxt();
    return true;
}

bool FormationRepository::remove(const std::string& id) {
    return std::remove(FORMATION_FILE(id).c_str()) == 0;
}

Formation FormationRepository::findById(const std::string& id) {
    std::ifstream ifs(FORMATION_FILE(id));
    if (!ifs.is_open()) return {};
    std::map<std::string, std::string> data;
    std::string line;
    while (std::getline(ifs, line)) {
        auto pos = line.find('=');
        if (pos == std::string::npos) continue;
        data[line.substr(0, pos)] = line.substr(pos + 1);
    }
    return Formation::To(data);
}

std::vector<Formation> FormationRepository::findAll() {
    std::vector<Formation> result;^
    DIR* dir = opendir(FORMATIONS_PATH);
    if (!dir) return result;
    struct dirent* entry;
    size_t extLen = strlen(EXTENSION_DB);
    while ((entry = readdir(dir)) != nullptr) {
        const char* name = entry->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) continue;
        size_t len = strlen(name);
        if (len > extLen && strcmp(name + len - extLen, EXTENSION_DB) == 0) {
            std::string id(name, len - extLen);
            result.push_back(findById(id));
        }
    }

    closedir(dir);
    return result;
}

std::vector<Formation> FormationRepository::findBy(std::function<bool(const Formation&)> predicate) {
    std::vector<Formation> matches;
    for (auto& f : findAll()) {
        if (predicate(f)) matches.push_back(f);
    }
    return matches;
}
std::string FormationRepository::getFilePath(const std::string& id){
    return FORMATION_FILE(id);
}

bool  FormationRepository::exists(const std::string& id) {
    std::ifstream ifs(getFilePath(id).c_str());
    return ifs.good();
}