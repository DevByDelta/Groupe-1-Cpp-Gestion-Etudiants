#include <fstream>
#include <sstream>
#include <map>
#include <dirent.h>
#include <cstdio>
#include <cstring>
#include <sys/stat.h>

#include "ClasseRepository.hpp"
#include "../const/pathsConst.hpp"

// Utilisation de la macro pour obtenir le chemin du fichier
std::string ClasseRepository::getFilePath(const std::string& id) {
    return CLASSES_PATH + std::string(id) + EXTENSION_DB;
}

// Vérifier la présence de l'objet
bool ClasseRepository::exists(const std::string& id) {
    std::ifstream ifs(getFilePath(id).c_str());
    return ifs.good();
}

// Sauvegarde l'objet (insert/update)
bool ClasseRepository::save(const Classe& obj) {
    std::ofstream ofs(getFilePath(obj.getId()).c_str());
    if (!ofs) return false;
    ofs << obj.toTxt();
    return true;
}

// Supprime le fichier d'un objet
bool ClasseRepository::remove(const std::string& id) {
    std::string filepath = getFilePath(id);
    return std::remove(filepath.c_str()) == 0;
}

// Charge un objet par id
Classe ClasseRepository::findById(const std::string& id) {
    std::ifstream ifs(getFilePath(id).c_str());
    if (!ifs) return Classe(); // Objet par défaut si non trouvé

    std::map<std::string, std::string> data;
    std::string line;
    while (std::getline(ifs, line)) {
        auto pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            data[key] = value;
        }
    }
    return Classe::To(data);
}

// Parcourt le dossier pour trouver toutes les classes
std::vector<Classe> ClasseRepository::findAll() {
    std::vector<Classe> result;

    DIR* dir = opendir(CLASSES_PATH);
    if (!dir) return result;

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        // Ignore . et ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        // On ne prend que les .txt
        std::string filename(entry->d_name);
        if (filename.size() > 4 && filename.substr(filename.size() - 4) == EXTENSION_DB) {
            std::ifstream ifs(std::string(CLASSES_PATH) + filename);
            std::map<std::string, std::string> data;
            std::string line;
            while (std::getline(ifs, line)) {
                auto pos = line.find('=');
                if (pos != std::string::npos) {
                    std::string key = line.substr(0, pos);
                    std::string value = line.substr(pos + 1);
                    data[key] = value;
                }
            }
            result.push_back(Classe::To(data));
        }
    }
    closedir(dir);
    return result;
}

// Recherche selon un prédicat (filtre)
std::vector<Classe> ClasseRepository::findBy(std::function<bool(const Classe&)> predicate) {
    std::vector<Classe> all = findAll();
    std::vector<Classe> filtered;
    for (size_t i = 0; i < all.size(); ++i) {
        if (predicate(all[i])) filtered.push_back(all[i]);
    }
    return filtered;
}
