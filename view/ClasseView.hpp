#pragma once

#include <string>
#include <vector>

#include "View.hpp"
#include "../model/entity/Classe.hpp"

class ClasseView : public View
{
public:
    Classe input();
    static ClasseView &instance();

    // méthodes de modifications
    void modifierNom(Classe &cl);
    void modifierFormationId(Classe &cl);
    void ajouterEtudiantCode(Classe &cl);

    // méthodes pures services
    Classe trouverClasse();
    void saisirEtEnregistrerClasse();
    void supprimerClasse();
    void rechercherClasse();
    void modifierClasse();

    // méthodes services utiles
    void afficherEffectifClasse();
    void afficherCoutFormationClasse();
    void displayAll(const std::vector<Classe> &classes);
};
