#pragma once
// CalendrierPaiementView.hpp  --  généré automatiquement
#include "CalendrierPaiement.hpp"
class CalendrierPaiementView {
public:
    static CalendrierPaiement saisir();
    static void saisirEtudiantCode(CalendrierPaiement& cp);
    static void saisirClasseId(CalendrierPaiement& cp);
    static void saisirEcheancier(CalendrierPaiement& cp);
};
