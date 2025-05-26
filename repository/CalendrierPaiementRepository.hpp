#pragma once

#include "CalendrierPaiement.hpp"

#include <string>
#include <vector>
#include <functional>

class CalendrierPaiementRepository {
private:
    static std::string getFilePath(const std::string& id);
public:
    static bool save(const CalendrierPaiement& obj);
    static bool exists(const std::string& id);
    static bool remove(const std::string& id);
    static CalendrierPaiement findById(const std::string& id);
    static std::vector<CalendrierPaiement> findAll();
    static std::vector<CalendrierPaiement> findBy(std::function<bool(const CalendrierPaiement&)> predicate);
};

