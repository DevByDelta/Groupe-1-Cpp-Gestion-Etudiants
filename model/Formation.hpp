#pragma once

#include <string>
#include "Niveau.hpp"

class Formation {
private:
    std::string id;
    std::string filiere;
    std::string anneeAcademique;
    Niveau::Type  niveau;
    int dureeAnnuelle;
    double coutAnnuel;

public:
    Formation();

    const std::string& getId() const;
    const std::string& getFiliere() const;
    Niveau::Type getNiveau() const;
    int getDureeAnnuelle() const;
    double getCoutAnnuel() const;

    void setFiliere(const std::string& filiere);
    void setNiveau(Niveau::Type niveau);
    void setDureeAnnuelle(int dureeAnnuelle);
    void setCoutAnnuel(double coutAnnuelle);

    std::string toString() const;

    ~Formation();
};
