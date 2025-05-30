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
    static void modifierFiliere(Formation &fomation);
    static void modifierNiveau(Formation &formation);
    static void modifierDureeAnnuelle(Formation &formation);
    static void modifierCoutAnnuel(Formation &Formation);
    // methode pure service
    static void saisirEtEnregistrerFormation();
    static void supprimerFormation();
    static void rechercherFormation();
    static void modifierFormation();
    static void displayAll(std::vector<Formation> formations);
    // methode service utils
    static void afficherRentabiliteParFiliere();
    static void afficherFormationsPopulaires();
};
