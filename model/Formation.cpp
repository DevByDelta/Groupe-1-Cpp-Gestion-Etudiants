#include <sstream>

#include "Formation.hpp"
#include "IDGenerator.hpp"
#include "Date.hpp"

#include "ReflectionMacros.hpp"

Formation::Formation()
{
    this->id = IDGenerator::generate("FR");
    this->anneeAcademique = Date::giveAnneeAcademique();
}

const std::string &Formation::getId() const { return this->id; }
void Formation::setId(const std::string &id) { this->id = id; }

const std::string &Formation::getFiliere() const { return this->filiere; }
void Formation::setFiliere(const std::string &filiere) { this->filiere = filiere; }

Niveau::Type Formation::getNiveau() const { return this->niveau; }
void Formation::setNiveau(Niveau::Type niveau) { this->niveau = niveau; }

int Formation::getDureeAnnuelle() const { return this->dureeAnnuelle; }
void Formation::setDureeAnnuelle(int dureeAnnuelle) { this->dureeAnnuelle = dureeAnnuelle; }

double Formation::getCoutAnnuel() const { return this->coutAnnuel; }
void Formation::setCoutAnnuel(double coutAnnuel) { this->coutAnnuel = coutAnnuel; }

const std::string &Formation::getAnneeAcademique() const { return this->anneeAcademique; }
void Formation::setAnneeAcademique(const std::string &anneeAcademique) { this->anneeAcademique = anneeAcademique; }

std::string Formation::toString() const{
    std::ostringstream oss;
    oss << "Formation[ID: " << id
        << ", Filiere: " << filiere
        << ", Annee Academique: " << anneeAcademique
        << ", Niveau: " << Niveau::toString(niveau)
        << ", Duree Annuelle: " << dureeAnnuelle
        << ", Cout Annuel: " << coutAnnuel << "]";
    return oss.str();
}

// Méthode toTxt pour sérialisation (PascalCase)
std::string Formation::toTxt() const
{
    std::ostringstream oss;
    oss << "Id=" << id << "\n";
    oss << "Filiere=" << filiere << "\n";
    oss << "AnneeAcademique=" << anneeAcademique << "\n";
    oss << "Niveau=" << Niveau::toString(niveau) << "\n";
    oss << "DureeAnnuelle=" << dureeAnnuelle << "\n";
    oss << "CoutAnnuel=" << coutAnnuel << "\n";
    return oss.str();
}
Formation Formation::To(const std::map<std::string, std::string>& data) {
    Formation obj;
    SET_STRING(data, obj, Id);
    SET_STRING(data, obj, Filiere);
    SET_STRING(data, obj, AnneeAcademique);
    SET_ENUM  (data, obj, Niveau, Niveau);
    SET_INT   (data, obj, DureeAnnuelle);
    SET_DOUBLE(data, obj, CoutAnnuel);
    return obj;
}

