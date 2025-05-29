#include <fstream>
#include <sstream>
#include <map>
#include <dirent.h>
#include <cstdio>
#include <cstring>

#include "ReglementRepository.hpp"
#include "../const/pathsConst.hpp"

std::string ReglementRepository::getFilePath(const std::string& id){
    return REGLEMENTS_PATH + std::string(id) + EXTENSION_DB;
}


bool  ReglementRepository::exists(const std::string& id) {
    std::ifstream ifs(getFilePath(id).c_str());
    return ifs.good();
}

bool ReglementRepository::save(const Reglement& obj) {
    std::ofstream ofs(getFilePath(obj.getId()));
    if (!ofs.is_open()) return false;
    ofs << obj.toTxt();
    return true;
}

bool ReglementRepository::remove(const std::string& id) {
    return std::remove(getFilePath(id).c_str()) == 0;
}

Reglement ReglementRepository::findById(const std::string& id) {
    std::ifstream ifs(getFilePath(id));
    if (!ifs.is_open()) return {};
    std::map<std::string, std::string> data;
    std::string line;
    while (std::getline(ifs, line)) {
        auto pos = line.find('=');
        if (pos == std::string::npos) continue;
        data[line.substr(0, pos)] = line.substr(pos + 1);
    }
    return Reglement::To(data);
}

std::vector<Reglement> ReglementRepository::findAll() {
    std::vector<Reglement> result;
    DIR* dir = opendir(REGLEMENTS_PATH);
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

std::vector<Reglement> ReglementRepository::findBy(std::function<bool(const Reglement&)> predicate) {
    std::vector<Reglement> matches;
    for (auto& r : findAll()) {
        if (predicate(r)) matches.push_back(r);
    }
    return matches;
}


