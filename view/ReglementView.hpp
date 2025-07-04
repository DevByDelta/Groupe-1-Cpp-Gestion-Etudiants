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
    static bool modifierMontant(Reglement &reglement, bool one=true);
    static bool modifierEtudiantCode(Reglement &reglement, bool one=true);
    static bool modifierClasseId(Reglement &Reglement, bool one=true);
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
