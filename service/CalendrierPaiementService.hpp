#pragma once
#include "CalendrierPaiement.hpp"
#include "Echeancier.hpp"

class CalendrierPaiementService {
public:
    CalendrierPaiementService();
    void validerMetierEtudiantCode(CalendrierPaiement& cp, const std::string& etudiantCode);
    void validerMetierClasseId(CalendrierPaiement& cp, const std::string& classeId);
    void validerMetierEchancier(CalendrierPaiement& cp, const Echeancier::Type& echeancier);
};
