#pragma once
#include "../model/entity/CalendrierPaiement.hpp"
#include "../model/enum/Echeancier.hpp"

class CalendrierPaiementService
{
private:
    CalendrierPaiementService() {}
    CalendrierPaiementService(const CalendrierPaiementService &) = delete;
    CalendrierPaiementService &operator=(const CalendrierPaiementService &) = delete;

public:
    static CalendrierPaiementService &instance();
    bool exist(const std::string &id);
    void validerMetierEtudiantCode(CalendrierPaiement &cp, const std::string &etudiantCode);
    void validerMetierClasseId(CalendrierPaiement &cp, const std::string &classeId);
    void validerMetierEchancier(CalendrierPaiement &cp, const Echeancier::Type &echeancier);
};
