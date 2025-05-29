#pragma once

#include <string>
#include <vector>
#include <functional>

#include "../model/entity/Reglement.hpp"

class ReglementRepository {
private:
    static std::string getFilePath(const std::string& id);
public:
    static bool save(const Reglement& obj);
    static bool remove(const std::string& id);
    static Reglement findById(const std::string& id);
    static std::vector<Reglement> findAll();
    static bool exists(const std::string& id);
    static std::vector<Reglement> findBy(std::function<bool(const Reglement&)> predicate);
};
