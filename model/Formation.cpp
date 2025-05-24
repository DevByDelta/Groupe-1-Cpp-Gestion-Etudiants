#include "Formation.hpp"
#include "IDGenerator.hpp"
#include <sstream>

Formation::Formation() {
    id = IDGenerator::generate<Formation>();
    filiere = "";
    niveau = Niveau::L1;  
    dureeAnnuelle = 0;
    coutAnnuel = 0.0;
}

Formation::Formation(const std::string& filiere,
                     Niveau niveau,
                     int dureeAnnuelle,
                     double coutAnnuel)
    : filiere(filiere),
      niveau(niveau),
      dureeAnnuelle(dureeAnnuelle),
      coutAnnuel(coutAnnuel) {
    id = IDGenerator::generate<Formation>();
}

const std::string& Formation::getId() const {
    return id;
}

const std::string& Formation::getFiliere() const {
    return filiere;
}

Niveau Formation::getNiveau() const {
    return niveau;
}

int Formation::getDureeAnnuelle() const {
    return dureeAnnuelle;
}

double Formation::getCoutAnnuel() const {
    return coutAnnuel;
}

void Formation::setFiliere(const std::string& f) {
    filiere = f;
}

void Formation::setNiveau(Niveau n) {
    niveau = n;
}

void Formation::setDureeAnnuelle(int duree) {
    dureeAnnuelle = duree;
}

void Formation::setCoutAnnuel(double cout) {
    coutAnnuel = cout;
}

std::string Formation::toString() const {
    std::ostringstream oss;
    oss << "Formation[ID=" << id
        << ", Filière=" << filiere
        << ", Niveau=" << niveauToString(niveau)
        << ", Durée=" << dureeAnnuelle << " mois"
        << ", Coût=" << coutAnnuel << " FCFA]";
    return oss.str();
}

Formation::~Formation() {}
