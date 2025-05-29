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
private:
    CalendrierPaiementView() {}
    CalendrierPaiementView(const CalendrierPaiementView &) = delete;
    CalendrierPaiementView &operator=(const CalendrierPaiementView &) = delete;

public:
    CalendrierPaiement input(const Etudiant &e, const Formation &f);
    static CalendrierPaiementView &instance();
    void displayAll(const std::vector<CalendrierPaiement> &cps);

    // méthodes de modification
    void modifierEtudiantCode(CalendrierPaiement &cp);
    void modifierClasseId(CalendrierPaiement &cp);
    void modifierEcheancier(CalendrierPaiement &cp);

};
