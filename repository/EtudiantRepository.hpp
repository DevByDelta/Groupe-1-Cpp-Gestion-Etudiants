#pragma once

#include <string>
#include <vector>
#include <functional>

#include "Etudiant.hpp"

class EtudiantRepository {
private:
    static std::string getFilePath(const std::string& id);
public:
    static bool save(const Etudiant& obj);
    static bool exists(const std::string& id);
    static bool remove(const std::string& code);
    static Etudiant findById(const std::string& code);
    static std::vector<Etudiant> findAll();
    static std::vector<Etudiant> findBy(std::function<bool(const Etudiant&)> predicate);
};