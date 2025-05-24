#include "Reglement.hpp"

// salim

Reglement::Reglement() {}

Reglement::~Reglement() {}
const std::string& Reglement::getclasseId()const {
    return this -> classeId;
}
const std::string& Reglement::getEtudiantCode()const {
    return this -> etudiantCode;
}
const Date& Reglement::getDate() const {
    return this -> date;
}
double Reglement::getMontant() const{
    return this -> montant;
}
void Reglement::setMontant(double montant){
    this -> montant = montant;
}
void Reglement::setEtudiantCode(const std::string& code) {
    this->etudiantCode = code;
}

void Reglement::setClasseId(const std::string& id) {
    this->classeId = id;
}
std::string Reglement::toString() const {
    
    return  "Reglement[ ID:" + id 
     + ", Etudiant Code:" + etudiantCode +
     ", Classe ID:" + classeId + 
     ", Date:" + date.toString() +
     ", Montant:" + std::to_string(montant)+"]";
;
}

