#include "Etudiant.hpp"
//Aminata
#include "IDGenerator.hpp"
#include <sstream>

Etudiant::Etudiant() {
    code = IDGenerator::generate<Etudiant>();
    nom = "";
    prenom = "";
    telephone = 0;
    email = "";
    estBoursier = false;
    estHandicape = false;
    familleNombreuse = false;
    estOrphelin = false;
}

Etudiant::Etudiant(const std::string& nom,
                   const std::string& prenom,
                   int telephone,
                   const std::string& email,
                   bool estBoursier,
                   bool estHandicape,
                   bool familleNombreuse,
                   bool estOrphelin)
    : nom(nom), prenom(prenom), telephone(telephone), email(email),
      estBoursier(estBoursier), estHandicape(estHandicape),
      familleNombreuse(familleNombreuse), estOrphelin(estOrphelin) {
    code = IDGenerator::generate<Etudiant>();
}

const std::string& Etudiant::getCode() const {
    return code;
}

const std::string& Etudiant::getNom() const {
    return nom;
}

const std::string& Etudiant::getPrenom() const {
    return prenom;
}

int Etudiant::getTelephone() const {
    return telephone;
}

const std::string& Etudiant::getEmail() const {
    return email;
}

const std::vector<std::string>& Etudiant::getClassesCode() const {
    return classesCode;
}

const std::vector<std::string>& Etudiant::getReglementsCode() const {
    return reglementsCode;
}

const std::vector<std::string>& Etudiant::getCalendriersCode() const {
    return calendriersCode;
}

void Etudiant::setNom(const std::string& n) {
    nom = n;
}

void Etudiant::setPrenom(const std::string& p) {
    prenom = p;
}

void Etudiant::setTelephone(int tel) {
    telephone = tel;
}

void Etudiant::setEmail(const std::string& mail) {
    email = mail;
}

void Etudiant::addClasse(const std::string& codeClasse) {
    classesCode.push_back(codeClasse);
}

void Etudiant::addReglement(const std::string& codeReglement) {
    reglementsCode.push_back(codeReglement);
}

void Etudiant::addCalendrier(const std::string& codeCalendrier) {
    calendriersCode.push_back(codeCalendrier);
}

std::string Etudiant::toString() const {
    std::ostringstream oss;
    oss << "Etudiant[Code=" << code
        << ", Nom=" << nom
        << ", Prénom=" << prenom
        << ", Téléphone=" << telephone
        << ", Email=" << email
        << ", Boursier=" << (estBoursier ? "Oui" : "Non")
        << ", Handicapé=" << (estHandicape ? "Oui" : "Non")
        << ", FamilleNombreuse=" << (familleNombreuse ? "Oui" : "Non")
        << ", Orphelin=" << (estOrphelin ? "Oui" : "Non")
        << ", NbClasses=" << classesCode.size()
        << ", NbRèglements=" << reglementsCode.size()
        << ", NbCalendriers=" << calendriersCode.size()
        << "]";
    return oss.str();
}

Etudiant::~Etudiant() {}
