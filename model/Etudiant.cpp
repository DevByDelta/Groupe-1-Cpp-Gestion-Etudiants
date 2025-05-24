#include "Etudiant.hpp"
#include "IDGenerator.hpp"  // Assurez-vous que cette classe existe
#include <sstream>

// Constructeur : génère un code automatiquement
Etudiant::Etudiant() {
    code = IDGenerator::generate("ETU");
}

// Getters
const std::string& Etudiant::getCode() const { return code; }
const std::string& Etudiant::getNom() const { return nom; }
const std::string& Etudiant::getPrenom() const { return prenom; }
const std::string& Etudiant::getTelephone() const { return telephone; }
const std::string& Etudiant::getEmail() const { return email; }
const std::string& Etudiant::getClasseCode() const { return classeCode; }
const std::vector<std::string>& Etudiant::getReglementsCode() const { return reglementsCode; }
const std::string& Etudiant::getCadPaieId() const { return cadPaieId; }

bool Etudiant::getEstBoursier() const { return estBoursier; }
bool Etudiant::getEstHandicape() const { return estHandicape; }
bool Etudiant::getFamilleNombreuse() const { return familleNombreuse; }
bool Etudiant::getEstOrphelin() const { return estOrphelin; }

// Setters
void Etudiant::setNom(const std::string& nom) {
    this->nom = nom;
}

void Etudiant::setPrenom(const std::string& prenom) {
    this->prenom = prenom;
}

void Etudiant::setTelephone(const std::string& telephone) {
    this->telephone = telephone;
}

void Etudiant::setEmail(const std::string& email) {
    this->email = email;
}

void Etudiant::setEstBoursier(bool estBoursier) {
    this->estBoursier = estBoursier;
}

void Etudiant::setEstHandicape(bool estHandicape) {
    this->estHandicape = estHandicape;
}

void Etudiant::setFamilleNombreuse(bool familleNombreuse) {
    this->familleNombreuse = familleNombreuse;
}

void Etudiant::setEstOrphelin(bool estOrphelin) {
    this->estOrphelin = estOrphelin;
}

void Etudiant::setclasseCode(const std::string& classeCode) {
    this->classeCode = classeCode;
}

void Etudiant::addReglement(const std::string& reglementCode) {
    reglementsCode.push_back(reglementCode);
}

void Etudiant::setCadPaieId(const std::string& cadPaieId) {
    this->cadPaieId = cadPaieId;
}

// toString — format compact sur une ligne
std::string Etudiant::toString() const {
    return "Etudiant[Code: " + code +
           ", Nom: " + nom +
           ", Prénom: " + prenom +
           ", Téléphone: " + telephone +
           ", Email: " + email +
           ", Classe: " + classeCode +
           ", CadPaieId: " + cadPaieId +
           ", Boursier: " + (estBoursier ? "Oui" : "Non") +
           ", Handicape: " + (estHandicape ? "Oui" : "Non") +
           ", FamilleNombreuse: " + (familleNombreuse ? "Oui" : "Non") +
           ", Orphelin: " + (estOrphelin ? "Oui" : "Non") +
           "]";
}
