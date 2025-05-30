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
    static void modifierNom(Classe &cl);
    static void modifierFormationId(Classe &cl);
    static void ajouterEtudiantCode(Classe &cl);

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
