#pragma once

#include <string>
#include <vector>

#include "../model/entity/CalendrierPaiement.hpp"
#include "../model/enum/Echeancier.hpp"
#include "View.hpp"
#include "EcheancierView.hpp"
#include "../model/entity/Etudiant.hpp"
#include "../model/entity/Formation.hpp"

class CalendrierPaiementView : public View
{
public:
    static CalendrierPaiement input(const Etudiant &e, const Formation &f);
    static void displayAll(const std::vector<CalendrierPaiement> &cps);

    // méthodes de modification
    static void modifierEtudiantCode(CalendrierPaiement &cp);
    static void modifierClasseId(CalendrierPaiement &cp);
    static void modifierEcheancier(CalendrierPaiement &cp);

};
