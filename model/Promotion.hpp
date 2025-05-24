#pragma once
// Promotion.hpp  --  généré automatiquement
// Kiné
#include<string>
#include<vector>
class Promotion {
private:
    std::string id;
    std::string annePromotion;
    std::string formationId;
    std::vector<std::string> classesId;public:
    const std::string& getId() const;
    const std::string& getAnnePromotion() const;
    const std::string& getFormationId() const;
    const std::vector<std::string>& getClassesId() const;
    void setAnnePromotion(const std::string& annePromotion);
    std::string toString() const;
    Promotion();
    ~Promotion();
};
