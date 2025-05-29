#pragma once
#include  "Reglement.hpp"
class ReglementService {
public:
    ReglementService();

    void validerMetierEtudiantCode(Reglement& r, const std::string& etudiantCode);
    void validerMetierClasseId   (Reglement& r, const std::string& classeId);
    void validerMetierMontant     (Reglement& r, double montant);
};
