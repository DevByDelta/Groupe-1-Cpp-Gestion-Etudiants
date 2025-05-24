#pragma once

#include "Niveau.hpp"
#include "IDGenerator.hpp"
// Formation.hpp  --  généré automatiquement
// Aminata

class Formation {
public:
Formation(const std::string& filiere,
              Niveau niveau, 
              int dureeAnnuelle,
              double coutAnnuel);
    const std::string& getId()      const;
    const std::string& getFiliere()          const;
    Niveau             getNiveau()           const;
    int                getDureeAnnuelle()    const;
    double             getCoutAnnuel()       const;

private:
        std::string id;
        std::string filiere;
        Niveau    niveau;
        int       dureeAnnuelle;
        double    CoutAnnuel;


};
