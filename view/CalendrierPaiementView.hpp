#pragma once

#include <string>
#include <vector>

#include "CalendrierPaiement.hpp"
#include "Echeancier.hpp"

class CalendrierPaiementView {
public:
    static CalendrierPaiement saisir();
    static std::string saisirEtudiantCode();
    static std::string saisirClasseId();
    static Echeancier::Type saisirEcheancier();
};
