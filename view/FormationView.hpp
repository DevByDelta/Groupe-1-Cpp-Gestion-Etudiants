#pragma once
#include "View.hpp"
#include <vector>
#include <string>

#include "../model/entity/Formation.hpp"

class FormationView : public View

{
private:
    FormationView() {};
    FormationView(const FormationView &) = delete;
    FormationView &operator=(const FormationView &) = delete;

public:
    Formation input();
    static FormationView &instance();

    // méthodes de modifications
    void modifierFiliere(Formation &fomation);
    void modifierNiveau(Formation &formation);
    void modifierDureeAnnuelle(Formation &formation);
    void modifierCoutAnnuel(Formation &Formation);
    // methode pure service
    void saisirEtEnregistrerFormation();
    void supprimerFormation();
    void rechercherFormation();
    void modifierFormation();
    void displayAll(std::vector<Formation> formations);
    // methode service utils
    void afficherRentabiliteParFiliere();
    void afficherFormationsPopulaires();
};
