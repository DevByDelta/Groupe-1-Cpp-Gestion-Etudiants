#pragma once

#include <string>
#include <vector>

#include "CalendrierPaiement.hpp"
#include "Echeancier.hpp"

class CalendrierPaiementView {

public:
    CalendrierPaiement input();
    std::string saisirEtudiantCode();
    std::string saisirClasseId();
    Echeancier::Type saisirEcheancier();
};
