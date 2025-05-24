#include "Classe.hpp"
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
const std::vector<std::string> Classe::getEtudiantCodes() const
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

std::string Classe::toString() const
{
    return "Classe[ID: " + id +
           ", Nom: " + nom +
           ", ID Formation: " + formationId + "]";
}
void Classe::addEtudiant(const std::string& codeEtudiant)
{
    this->etudiantCodes.push_back(codeEtudiant);
}

