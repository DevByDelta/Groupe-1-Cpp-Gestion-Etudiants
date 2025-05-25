#pragma once

#include <string>
#include <map>
#include "Niveau.hpp"

class Formation {
private:
    std::string id;
    std::string filiere;
    std::string anneeAcademique;
    Niveau::Type niveau;
    int dureeAnnuelle;
    double coutAnnuel;

    void setId(const std::string& id);
    void setAnneeAcademique(const std::string& anneeAcademique);

public:
    Formation();

    // Getters
    const std::string& getId() const;
    const std::string& getFiliere() const;
    const std::string& getAnneeAcademique() const;
    Niveau::Type getNiveau() const;
    int getDureeAnnuelle() const;
    double getCoutAnnuel() const;

    // Setters métier
    void setFiliere(const std::string& filiere);
    void setNiveau(Niveau::Type niveau);
    void setDureeAnnuelle(int dureeAnnuelle);
    void setCoutAnnuel(double coutAnnuel);

    // Affichage & sérialisation
    std::string toString() const;
    std::string toTxt() const;

    // Import (reconstruction)
    static Formation To(const std::map<std::string, std::string>& data);
};
