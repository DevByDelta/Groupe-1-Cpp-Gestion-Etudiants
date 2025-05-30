#pragma once

#include <string>
#include <vector>
#include "View.hpp"
#include "../model/entity/Reglement.hpp"

class ReglementView : public View
{
public:
    static Reglement input();
    static void displayAll(std::vector<Reglement> reglements);

    // méthodes de modifications
    static void modifierMontant(Reglement &reglement);
    static void modifierEtudiantCode(Reglement &reglement);
    static void modifierClasseId(Reglement &Reglement);
    // methode pure service
    static void ajouterReglement();
    static void modifierReglement();
    static void supprimerReglement();
    static void rechercherReglement();
    static void listerReglements();
    // methode util
    static void afficherReglementsEtudiantParAnnee();
    static void afficherReliquatEtudiant();
    static void afficherChiffreAffaireEtablissement();
    static void afficherRentabiliteParFiliere();
};
