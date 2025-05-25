#include "EtudiantRepository.hpp"
#include <fstream>
#include <sstream>
#include <map>
#include <dirent.h>
#include <cstdio>
#include <cstring>

bool EtudiantRepository::save(const Etudiant& obj) {
    std::ofstream ofs(ETUDIANT_FILE(obj.getCode()));
    if (!ofs.is_open()) return false;
    ofs << obj.toTxt();
    return true;
}

bool EtudiantRepository::remove(const std::string& code) {
    return std::remove(ETUDIANT_FILE(code).c_str()) == 0;
}

Etudiant EtudiantRepository::findById(const std::string& code) {
    std::ifstream ifs(ETUDIANT_FILE(code));
    if (!ifs.is_open()) return {};
    std::map<std::string, std::string> data;
    std::string line;
    while (std::getline(ifs, line)) {
        auto pos = line.find('=');
        if (pos == std::string::npos) continue;
        data[line.substr(0, pos)] = line.substr(pos + 1);
    }
    return Etudiant::To(data);
}

std::vector<Etudiant> EtudiantRepository::findAll() {
    std::vector<Etudiant> result;
    DIR* dir = opendir(ETUDIANTS_PATH);
    if (!dir) return result;
    struct dirent* entry;
    size_t extLen = strlen(EXTENSION_DB);
    while ((entry = readdir(dir)) != nullptr) {
        const char* name = entry->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) continue;
        size_t len = strlen(name);
        if (len > extLen && strcmp(name + len - extLen, EXTENSION_DB) == 0) {
            std::string code(name, len - extLen);
            result.push_back(findById(code));
        }
    }
    closedir(dir);
    return result;
}

std::vector<Etudiant> EtudiantRepository::findBy(std::function<bool(const Etudiant&)> predicate) {
    std::vector<Etudiant> matches;
    for (auto& e : findAll()) {
        if (predicate(e)) matches.push_back(e);
    }
    return matches;
}
std::string EtudiantRepository::getFilePath(const std::string& id){
    return ETUDIANT_FILE(id);
}

bool  EtudiantRepository::exists(const std::string& id) {
    std::ifstream ifs(getFilePath(id).c_str());
    return ifs.good();
}