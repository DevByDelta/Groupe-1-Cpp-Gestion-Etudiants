#include "Classe.hpp"
#include "ReflectionMacros.hpp"
#include "IDGenerator.hpp"

#include "FormationRepository.hpp"
#include "EtudiantRepository.hpp"

Classe::Classe()
{
    this->id = IDGenerator::generate("CL");
}

// getters
const std::string& Classe::getId() const{ return this->id; }
const std::string& Classe::getNom() const{ return this->nom; }
const std::string& Classe::getFormationId() const{ return this->formationId; }
const std::vector<std::string>& Classe::getEtudiantCodes() const{ return this->etudiantCodes; }

// setters
void Classe::setNom(const std::string& nom){ this->nom = nom; }
void Classe::setFormationId(const std::string& formationId){
    if (!FormationRepository::exists(formationId)) {
        throw std::runtime_error("Formation ID invalide : " + formationId);
    }
    this->formationId = formationId;
}
void Classe::setId(const std::string& id){ this->id = id; }

// métiers
std::string Classe::toString() const{
    std::ostringstream oss;
    oss << "Classe[ID: " << id
        << ", nom: " << nom
        << ", ID Formation: " << formationId
        << "]";
    return oss.str();
}

// méthode d'ajout
void Classe::addEtudiant(const std::string& codeEtudiant){
    if (!EtudiantRepository::exists(codeEtudiant)) {
        throw std::runtime_error("Etudiant CODE invalide : " + codeEtudiant);
    }
    this->etudiantCodes.push_back(codeEtudiant);
}

std::string Classe::toTxt() const{
    std::ostringstream oss;
    oss << "Id=" << id << "\n";
    oss << "Nom=" << nom << "\n";
    oss << "FormationId=" << formationId << "\n";
    oss << "EtudiantCodes=";
    for (size_t i = 0; i < etudiantCodes.size(); ++i) {
        oss << etudiantCodes[i];
        if (i != etudiantCodes.size() - 1) oss << ",";
    }
    oss << "\n";
    return oss.str();
}

Classe Classe::To(const std::map<std::string, std::string>& data) {
    Classe obj;
    SET_STRING(data, obj, Id);
    SET_STRING(data, obj, Nom);
    SET_STRING(data, obj, FormationId);
    SET_LIST(data, obj, EtudiantCodes, addEtudiant);
    return obj;
}
