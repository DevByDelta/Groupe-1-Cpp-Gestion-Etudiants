#pragma once

#include <string>
#include <vector>

#include "View.hpp"
#include "../model/entity/Classe.hpp"

class ClasseView : public View
{
public:
    static Classe input();

    // méthodes de modifications
    static bool modifierNom(Classe &cl, bool one=false);
    static bool modifierFormationId(Classe &cl, bool one=false);

    // méthodes pures services
    static Classe trouverClasse();
    static void saisirEtEnregistrerClasse();
    static void supprimerClasse();
    static void rechercherClasse();
    static void modifierClasse();
    static void afficherTous();

    // méthodes services utiles
    static void afficherEffectifClasse();
    static void afficherCoutFormationClasse();
    static void displayAll(std::vector<Classe> classes);
};
