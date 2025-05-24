#include "Promotion.hpp"
// Kiné

Promotion::Promotion() {}

Promotion::~Promotion() {}
const std::string& Promotion::getId() const {
    return this -> id;
}

const std::string& Promotion::getAnnePromotion() const {
    return this -> annePromotion;
}

const std::string& Promotion::getFormationId() const {
    return this -> formationId;
}

const std::vector<std::string>& Promotion::getClassesId() const {
    return this -> classesId;
}
void Promotion::setAnnePromotion(const std::string& annePromotion) {
    this -> annePromotion = annePromotion;
}
std::string Promotion::toString() const {
    std::string result = "Promotion :\n";
    result += "ID : " + id + "\n";
    result += "Année : " + annePromotion + "\n";
    result += "Formation ID : " + formationId + "\n";
    result += "Classes ID : ";

    for (const std::string& cid : classesId) {
        result += cid + " ";
    }

    return result;
}