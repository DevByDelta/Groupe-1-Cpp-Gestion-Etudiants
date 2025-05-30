#include <algorithm>

#include "Classe.hpp"
#include "../ReflectionMacros.hpp"
#include "../utils/IDGenerator.hpp"

Classe::Classe(
    std::string formationId)
    : id(IDGenerator::generate("CL")),
      nom(""),
      formationId(formationId)
{}

// getters
const std::string &Classe::getId() const { return this->id; }
const std::string &Classe::getNom() const { return this->nom; }
const std::string &Classe::getFormationId() const { return this->formationId; }

// setters
void Classe::setNom(const std::string &nom)
{
    if (nom.size() < 3)
    {
        throw std::invalid_argument("Le nom doit avoir au minimum 3 caractères !");
    }
    this->nom = nom;
}
void Classe::setFormationId(const std::string &formationId)
{
    this->formationId = formationId;
}
void Classe::setId(const std::string &id) { this->id = id; }

// métiers
std::string Classe::toString() const
{
    std::ostringstream oss;
    oss << "Classe[ID: " << id
        << ", nom: " << nom
        << ", ID Formation: " << formationId
        << "]";
    return oss.str();
}


std::string Classe::toTxt() const
{
    std::ostringstream oss;
    oss << "Id=" << id << "\n";
    oss << "Nom=" << nom << "\n";
    oss << "FormationId=" << formationId << "\n";
    return oss.str();
}

Classe Classe::To(const std::map<std::string, std::string> &data)
{
    Classe obj;
    SET_STRING(data, obj, Id);
    SET_STRING(data, obj, Nom);
    SET_STRING(data, obj, FormationId);
    return obj;
}
