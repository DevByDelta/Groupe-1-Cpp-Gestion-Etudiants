#include "Etudiant.hpp"
#include "IDGenerator.hpp"
#include "ReflectionMacros.hpp"
#include <sstream>

Etudiant::Etudiant() {
    code = IDGenerator::generate("ETU");
}

const std::string& Etudiant::getCode() const { return code; }
void Etudiant::setCode(const std::string& code){
    this->code = code;
}

const std::string& Etudiant::getNom() const { return nom; }
void Etudiant::setNom(const std::string& nom) {
    this->nom = nom;
}

const std::string& Etudiant::getPrenom() const { return prenom; }
void Etudiant::setPrenom(const std::string& prenom) {
    this->prenom = prenom;
}

const std::string& Etudiant::getTelephone() const { return telephone; }
void Etudiant::setTelephone(const std::string& telephone) {
    this->telephone = telephone;
}

const std::string& Etudiant::getEmail() const { return email; }
void Etudiant::setEmail(const std::string& email) {
    this->email = email;
}

const std::string& Etudiant::getClasseId() const { return classeId; }
void Etudiant::setClasseId(const std::string& classeId) {
    this->classeId = classeId;
}

const std::vector<std::string>& Etudiant::getReglementsId() const { return reglementsId; }
void Etudiant::setReglementsId(const std::vector<std::string>& reglementsId) {
    this->reglementsId = reglementsId;
}

const std::string& Etudiant::getCadPaieId() const { return cadPaieId; }
void Etudiant::setCadPaieId(const std::string& cadPaieId) {
    this->cadPaieId = cadPaieId;
}

bool Etudiant::getEstBoursier() const { return estBoursier; }
void Etudiant::setEstBoursier(bool estBoursier) {
    this->estBoursier = estBoursier;
}

bool Etudiant::getEstHandicape() const { return estHandicape; }
void Etudiant::setEstHandicape(bool estHandicape) {
    this->estHandicape = estHandicape;
}

bool Etudiant::getFamilleNombreuse() const { return familleNombreuse; }
void Etudiant::setFamilleNombreuse(bool familleNombreuse) {
    this->familleNombreuse = familleNombreuse;
}

bool Etudiant::getEstOrphelin() const { return estOrphelin; }
void Etudiant::setEstOrphelin(bool estOrphelin) {
    this->estOrphelin = estOrphelin;
}

void Etudiant::addReglementId(const std::string& reglementId) {
    reglementsId.push_back(reglementId);
}

// toString
std::string Etudiant::toString() const {
    std::ostringstream oss;
    oss << "Etudiant[Code: " << code
        << ", Nom: " << nom
        << ", Prénom: " << prenom
        << ", Téléphone: " << telephone
        << ", Email: " << email
        << ", Classe: " << classeId
        << ", CadPaieId: " << cadPaieId
        << ", Boursier: " << (estBoursier ? "Oui" : "Non")
        << ", Handicape: " << (estHandicape ? "Oui" : "Non")
        << ", FamilleNombreuse: " << (familleNombreuse ? "Oui" : "Non")
        << ", Orphelin: " << (estOrphelin ? "Oui" : "Non")
        << "]";
    return oss.str();
}

// toTxt : sérialisation pour sauvegarde fichier
std::string Etudiant::toTxt() const {
    std::ostringstream oss;
    oss << "Code=" << code << "\n";
    oss << "Nom=" << nom << "\n";
    oss << "Prenom=" << prenom << "\n";
    oss << "Telephone=" << telephone << "\n";
    oss << "Email=" << email << "\n";
    oss << "ClasseId=" << classeId << "\n";
    oss << "CadPaieId=" << cadPaieId << "\n";
    oss << "EstBoursier=" << (estBoursier ? "1" : "0") << "\n";
    oss << "EstHandicape=" << (estHandicape ? "1" : "0") << "\n";
    oss << "FamilleNombreuse=" << (familleNombreuse ? "1" : "0") << "\n";
    oss << "EstOrphelin=" << (estOrphelin ? "1" : "0") << "\n";
    oss << "ReglementsId=";
    for (size_t i = 0; i < reglementsId.size(); ++i) {
        oss << reglementsId[i];
        if (i != reglementsId.size() - 1) oss << ",";
    }
    oss << "\n";
    return oss.str();
}
