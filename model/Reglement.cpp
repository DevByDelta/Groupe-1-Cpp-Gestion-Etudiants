#include "Reglement.hpp"
#include "IDGenerator.hpp"
#include "ReflectionMacros.hpp"
#include <sstream>

Reglement::Reglement() {
    this->id = IDGenerator::generate("RE");
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
