#pragma once

#include <string>
#include <vector>
#include <functional>
#include "Formation.hpp"
#include "PathsAndMacros.hpp"  // FORMATION_FILE(id), FORMATIONS_PATH, EXTENSION_DB

class FormationRepository {
private:
    static std::string getFilePath(const std::string& id);
public:
    static bool save(const Formation& obj);
    static bool exists(const std::string& id);
    static bool remove(const std::string& id);
    static Formation findById(const std::string& id);
    static std::vector<Formation> findAll();
    static std::vector<Formation> findBy(std::function<bool(const Formation&)> predicate);
};