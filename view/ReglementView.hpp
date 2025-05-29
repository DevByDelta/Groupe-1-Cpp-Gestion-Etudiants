#pragma once

#include <string>
#include <vector>
#include "View.hpp"
#include "../model/entity/Reglement.hpp"

class ReglementView : public View
{
private:
    ReglementView() {}
    ReglementView(const ReglementView &) = delete;
    ReglementView &operator=(const ReglementView &) = delete;

public:
    Reglement input();
    static ReglementView &instance();
    void displayAll(std::vector<Reglement> reglements);

    // méthodes de modifications
    void modifierMontant(Reglement &reglement);
    void modifierEtudiantCode(Reglement &reglement);
    void modifierClasseId(Reglement &Reglement);
    // methode pure service
    void ajouterReglement();
    void modifierReglement();
    void supprimerReglement();
    void rechercherReglement();
    void listerReglements();
    // methode util
    void afficherReglementsEtudiantParAnnee();
    void afficherReliquatEtudiant();
    void afficherChiffreAffaireEtablissement();
    void afficherRentabiliteParFiliere();
};
