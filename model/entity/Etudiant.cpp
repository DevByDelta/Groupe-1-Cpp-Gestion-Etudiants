#include <sstream>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <regex>
#include <stdexcept>

#include "Etudiant.hpp"
#include "../utils/IDGenerator.hpp"
#include "../ReflectionMacros.hpp"

Etudiant::Etudiant(
    const std::string &classeId = "",
    const std::string &cadPaieId = ""
)
{
    this->code = IDGenerator::generate("ETU");
    this->nom = "";
    this->prenom = "";
    this->telephone = "";
    this->email = "";
    this->classeId = "";
    this->cadPaieId = "";
}

const std::string &Etudiant::getCode() const { return code; }
void Etudiant::setCode(const std::string &code)
{
    this->code = code;
}

const std::string &Etudiant::getNom() const { return nom; }
void Etudiant::setNom(const std::string &nom)
{
    this->nom = nom;
}

const std::string &Etudiant::getPrenom() const { return prenom; }
void Etudiant::setPrenom(const std::string &prenom)
{
    this->prenom = prenom;
}

const std::string &Etudiant::getTelephone() const { return telephone; }
void Etudiant::setTelephone(const std::string &telephone)
{
    if (telephone.size() != 9 ||
        !std::all_of(telephone.begin(), telephone.end(), ::isdigit))
    {
        throw std::invalid_argument("Le numéro de téléphone doit contenir exactement 9 chiffres.");
    }
    this->telephone = telephone;
}

const std::string &Etudiant::getEmail() const { return email; }
void Etudiant::setEmail(const std::string &email)
{
    static const std::regex pattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!std::regex_match(email, pattern))
    {
        throw std::invalid_argument("Email invalide !");
    }
    this->email = email;
}

const std::string &Etudiant::getClasseId() const { return classeId; }
void Etudiant::setClasseId(const std::string &classeId)
{
    this->classeId = classeId;
}


const std::string &Etudiant::getCadPaieId() const { return cadPaieId; }
void Etudiant::setCadPaieId(const std::string &cadPaieId)
{
    this->cadPaieId = cadPaieId;
}

bool Etudiant::getEstBoursier() const { return estBoursier; }
void Etudiant::setEstBoursier(bool estBoursier)
{
    this->estBoursier = estBoursier;
}

bool Etudiant::getEstHandicape() const { return estHandicape; }
void Etudiant::setEstHandicape(bool estHandicape)
{
    this->estHandicape = estHandicape;
}

bool Etudiant::getFamilleNombreuse() const { return familleNombreuse; }
void Etudiant::setFamilleNombreuse(bool familleNombreuse)
{
    this->familleNombreuse = familleNombreuse;
}

bool Etudiant::getEstOrphelin() const { return estOrphelin; }
void Etudiant::setEstOrphelin(bool estOrphelin)
{
    this->estOrphelin = estOrphelin;
}


// toString
std::string Etudiant::toString() const
{
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
std::string Etudiant::toTxt() const
{
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
    return oss.str();
}

Etudiant Etudiant::To(const std::map<std::string, std::string> &data)
{
    Etudiant obj;

    SET_STRING(data, obj, Code);
    SET_STRING(data, obj, Nom);
    SET_STRING(data, obj, Prenom);
    SET_STRING(data, obj, Telephone);
    SET_STRING(data, obj, Email);
    SET_STRING(data, obj, ClasseId);
    SET_STRING(data, obj, CadPaieId);
    SET_BOOL(data, obj, EstBoursier);
    SET_BOOL(data, obj, EstHandicape);
    SET_BOOL(data, obj, FamilleNombreuse);
    SET_BOOL(data, obj, EstOrphelin);

    return obj;
}
