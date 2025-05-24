#pragma once

#include <string>
#include "Niveau.hpp"

class Formation {
private:
    std::string id;
    std::string filiere;
    Niveau niveau;
    int dureeAnnuelle;
    double coutAnnuel;

public:
    Formation();
    Formation(const std::string& filiere,
              Niveau niveau,
              int dureeAnnuelle,
              double coutAnnuel);

    const std::string& getId() const;
    const std::string& getFiliere() const;
    Niveau getNiveau() const;
    int getDureeAnnuelle() const;
    double getCoutAnnuel() const;

    void setFiliere(const std::string& f);
    void setNiveau(Niveau n);
    void setDureeAnnuelle(int duree);
    void setCoutAnnuel(double cout);

    std::string toString() const;

    ~Formation();
};
