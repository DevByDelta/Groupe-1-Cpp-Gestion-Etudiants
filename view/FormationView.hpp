#pragma once
#include "View.hpp"
#include <vector>
#include <string>

#include "../model/entity/Formation.hpp"

class FormationView : public View

{

public:
    static Formation input();

    // méthodes de modifications
    static bool modifierFiliere(Formation &fomation, bool one=true);
    static bool modifierNiveau(Formation &formation, bool one=true);
    static bool modifierDureeAnnuelle(Formation &formation, bool one=true);
    static bool modifierCoutAnnuel(Formation &Formation, bool one=true);
    // methode pure service
    static void saisirEtEnregistrerFormation();
    static void supprimerFormation();
    static void rechercherFormation();
    static void modifierFormation();
    static void displayAll(std::vector<Formation> formations);
    static void afficherTousFormations();
    // methode service utils
    static void afficherFilierePlusRentable();
    static void afficherFormationsPopulaires();
};
