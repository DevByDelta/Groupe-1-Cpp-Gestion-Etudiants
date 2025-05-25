#include "Classe.hpp"
#include "ReflectionMacros.hpp"
#include "IDGenerator.hpp"
// Kiné

Classe::Classe()
{
    this->id = IDGenerator::generate("CL");
}

const std::string& Classe::getId() const
{
    return this->id;
}
const std::string& Classe::getNom() const
{
    return this->nom;
}
const std::string& Classe::getFormationId() const
{
    return this->formationId;
}
const std::vector<std::string>& Classe::getEtudiantCodes() const
{
    return this->etudiantCodes;
}

void Classe::setNom(const std::string& nom)
{
    this->nom = nom;
}
void Classe::setFormationId(const std::string& formationId)
{
    this->formationId = formationId;
}
void Classe::setId(const std::string& id)
{
    this->id = id;
}
void Classe::setEtudiantCodes(const std::vector<std::string>& codes)
{
    this->etudiantCodes = codes;
}

std::string Classe::toString() const
{
    std::ostringstream oss;
    oss << "Classe[ID: " << id
        << ", nom: " << nom
        << ", ID Formation: " << formationId
        << "]";
    return oss.str();
}

void Classe::addEtudiant(const std::string& codeEtudiant)
{
    this->etudiantCodes.push_back(codeEtudiant);
}

std::string Classe::toTxt() const
{
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
    SET_STRING(data, obj, Id);            // "Id" => setId
    SET_STRING(data, obj, Nom);           // "Nom" => setNom
    SET_STRING(data, obj, FormationId);   // "FormationId" => setFormationId
    SET_LIST(data, obj, EtudiantCodes, addEtudiant); // "EtudiantCodes" => addEtudiant (pour chaque code)
    return obj;
}
