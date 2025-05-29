#pragma once
#include "Formation.hpp"
#include  "Niveau.hpp"
#include <vector>
#include <string>

class FormationService {
public:
    FormationService();
    void validerMertierFiliere(Formation& f,const std::string& filiere);
    void validerMertierNiveau(Formation& f,const Niveau::Type& niveau);
    void validerMetierDureeAnnuelle(Formation& f, int dureeAnnuelle);
    void validerMetierCoutAnnuel(Formation& f, double coutAnnuel);
    bool ajouterFormation(const Formation& etudiant);
    bool supprimerFormation(const std::string& formationId);
    Formation rechercherFormation(const std::string& formationId);
    std::vector<Formation> avoirTousFormations();
};
