#include <sstream>

#include "Reglement.hpp"
#include "../utils/IDGenerator.hpp"

#include "../ReflectionMacros.hpp"



Reglement::Reglement() {
    this->id = IDGenerator::generate("RE");
    this->date = Date();
    id="";
    etudiantCode="";
    classeId="";
    montant=0;
}

const std::string& Reglement::getId() const {
    return this->id;
}

const std::string& Reglement::getClasseId() const {
    return this->classeId;
}

const std::string& Reglement::getEtudiantCode() const {
    return this->etudiantCode;
}

const Date& Reglement::getDate() const {
    return this->date;
}

double Reglement::getMontant() const {
    return this->montant;
}

void Reglement::setId(const std::string& id) {
    this->id = id;
}

void Reglement::setMontant(double montant) {
    if (montant<0.0){
        throw std::runtime_error("Montant invalide : " + std::to_string(montant));
    }
    this->montant = montant;
}

void Reglement::setEtudiantCode(const std::string& etudiantCode) {
    this->etudiantCode = etudiantCode;
}

void Reglement::setClasseId(const std::string& classeId) {
    this->classeId = classeId;
}

void Reglement::setDate(const Date& date) {
    this->date = date;
}

std::string Reglement::toString() const {
    std::ostringstream oss;
    oss << "Reglement[ID: " << id
        << ", Etudiant Code: " << etudiantCode
        << ", Classe ID: " << classeId
        << ", Date: " << date.toString()
        << ", Montant: " << montant
        << "]";
    return oss.str();
}

std::string Reglement::toTxt() const {
    std::ostringstream oss;
    oss << "Id=" << id << "\n";
    oss << "EtudiantCode=" << etudiantCode << "\n";
    oss << "ClasseId=" << classeId << "\n";
    oss << "Date=" << date.toString() << "\n";
    oss << "Montant=" << montant << "\n";
    return oss.str();
}

Reglement Reglement::To(const std::map<std::string, std::string>& data) {
    Reglement obj;
    SET_STRING(data, obj, Id);
    SET_STRING(data, obj, EtudiantCode);
    SET_STRING(data, obj, ClasseId);
    SET_DATE  (data, obj, Date);
    SET_DOUBLE(data, obj, Montant);
    return obj;
}
