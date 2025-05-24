#include "Formation.hpp"
#include "IDGenerator.hpp"
#include <sstream>

Formation::Formation()
{
    this->id = IDGenerator::generate("FR");
}

const std::string &Formation::getId() const
{
    return this->id;
}

const std::string &Formation::getFiliere() const
{
    return this->filiere;
}

Niveau::Type Formation::getNiveau() const
{
    return this->niveau;
}

int Formation::getDureeAnnuelle() const
{
    return this->dureeAnnuelle;
}

double Formation::getCoutAnnuel() const
{
    return this->coutAnnuel;
}

void Formation::setFiliere(const std::string &filiere)
{
    this->filiere = filiere;
}

void Formation::setNiveau(Niveau::Type niveau)
{
    this->niveau = niveau;
}

void Formation::setDureeAnnuelle(int dureeAnnuelle)
{
    this->dureeAnnuelle = dureeAnnuelle;
}

void Formation::setCoutAnnuel(double coutAnnuel)
{
    this->coutAnnuel = coutAnnuel;
}

std::string Formation::toString() const
{
    return "Formation[ID: " + id +
           ", filiere: " + filiere +
           ", Annee Academique: " + anneeAcademique +
           ", Niveau: " + Niveau::toString(niveau) +
           ", Duree Annuelle: " + std::to_string(dureeAnnuelle) +
           ", Cout Annuel: " + std::to_string(coutAnnuel) + "]";
}

Formation::~Formation() {}
