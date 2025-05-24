#include "Etudiant.hpp"
#include "IDGenerator.hpp"
#include <sstream>


Etudiant::Etudiant() {
    code = IDGenerator::generate("ETU");
}

// Getters
const std::string& Etudiant::getCode() const { return code; }
const std::string& Etudiant::getNom() const { return nom; }
const std::string& Etudiant::getPrenom() const { return prenom; }
const std::string& Etudiant::getTelephone() const { return telephone; }
const std::string& Etudiant::getEmail() const { return email; }
const std::string& Etudiant::getClasseId() const { return classeId; }
const std::vector<std::string>& Etudiant::getReglementsId() const { return reglementsId; }
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

void Etudiant::setClasseId(const std::string& classeId) {
    this->classeId = classeId;
}

void Etudiant::addReglementId(const std::string& reglementId) {
    reglementsId.push_back(reglementId);
}

void Etudiant::setCadPaieId(const std::string& cadPaieId) {
    this->cadPaieId = cadPaieId;
}

// toString
std::string Etudiant::toString() const {
    return "Etudiant[Code: " + code +
           ", Nom: " + nom +
           ", Prénom: " + prenom +
           ", Téléphone: " + telephone +
           ", Email: " + email +
           ", Classe: " + classeId +
           ", CadPaieId: " + cadPaieId +
           ", Boursier: " + (estBoursier ? "Oui" : "Non") +
           ", Handicape: " + (estHandicape ? "Oui" : "Non") +
           ", FamilleNombreuse: " + (familleNombreuse ? "Oui" : "Non") +
           ", Orphelin: " + (estOrphelin ? "Oui" : "Non") +
           "]";
}
