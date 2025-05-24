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
void Promotion::setFormationId(const std::string& id) {
    this -> formationId = id;
}

const std::vector<std::string>& Promotion::getClassesId() const {
    return this -> classesId;
}
void Promotion::setAnnePromotion(const std::string& annePromotion) {
    this -> annePromotion = annePromotion;
}
std::string Promotion::toString() const {
    return "Promotion[ ID:" + id +
     ", Année de promotion:" + annePromotion + 
     ", Formation ID:" + formationId + "]";
}