#pragma once
#include "../model/entity/Reglement.hpp"
#include "../model/entity/Classe.hpp"

class ReglementService {
private:
    ReglementService() {}
    ReglementService(const ReglementService &) = delete;
    ReglementService &operator=(const ReglementService &) = delete;

public:
    static ReglementService &instance();
    bool exist(const std::string& id);

    void validerMetierEtudiantCode(Reglement& r, const std::string& etudiantCode);
    void validerMetierClasseId(Reglement& r, const std::string& classeId);
    void validerMetierMontant(Reglement& r, double montant);

    bool ajouterReglement(const Reglement& reglement);
    bool supprimerReglement(const std::string reglementId);
    std::vector<Reglement> avoirTousReglementPourUnEtudiant(const std::string& etudiantode );
    double avoirReliquatEtudiant(const std::string& etudiantCode);
    double calculerReglementTotalEtudiant(const std::string& etudiantCode);
    double avoirChiffreAffaireEtabilissement();
    double calculerTotalReglementClasse(const Classe& classe);
    Reglement rechercherReglement(const std::string& reglementId);
    std::vector<Reglement> avoirTousReglements();
    std::map<std :: string,double> ReglementService::rentabiliteParFiliere();
};
