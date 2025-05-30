#pragma once
#include "../model/entity/CalendrierPaiement.hpp"
#include "../model/enum/Echeancier.hpp"

class CalendrierPaiementService
{
public:
    static bool exist(const std::string &id);
    static void validerMetierEtudiantCode(CalendrierPaiement &cp, const std::string &etudiantCode);
    static void validerMetierClasseId(CalendrierPaiement &cp, const std::string &classeId);
    static void validerMetierEchancier(CalendrierPaiement &cp, const Echeancier::Type &echeancier);
};
