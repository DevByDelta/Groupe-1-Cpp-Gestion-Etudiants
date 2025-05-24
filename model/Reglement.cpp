#include "Reglement.hpp"
#include "IDGenerator.hpp"
// salim

Reglement::Reglement() {
    this -> id = IDGenerator::generate("RE");
}

Reglement::~Reglement() {}
const std::string& Reglement::getId()const{
    return this -> id;
}
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
void Reglement::setEtudiantCode(const std::string& etudiantCode) {
    this -> etudiantCode = etudiantCode;
}
void Reglement::setClasseId(const std::string& classeId) {
    this -> classeId = classeId;
}
std::string Reglement::toString() const {
    return  "Reglement[ID:" + id 
     + ", Etudiant Code:" + etudiantCode +
     ", Classe ID:" + classeId + 
     ", Date:" + date.toString() +
     ", Montant:" + std::to_string(montant)+"]";
;
}

