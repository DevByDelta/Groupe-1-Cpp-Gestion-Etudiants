#pragma once
#include "../model/entity/Reglement.hpp"
#include "../model/entity/Classe.hpp"

class ReglementService
{
public:
    static bool exist(const std::string &id);

    static void validerMetierEtudiantCode(Reglement &r, const std::string &etudiantCode);
    static void validerMetierClasseId(Reglement &r, const std::string &classeId);
    static void validerMetierMontant(Reglement &r, double montant);

    static bool ajouterReglement(const Reglement &reglement);
    static bool supprimerReglement(const std::string reglementId);
    static std::vector<Reglement> avoirTousReglementPourUnEtudiant(const std::string &etudiantode);
    static double avoirReliquatEtudiant(const std::string &etudiantCode);
    static double calculerReglementTotalEtudiant(const std::string &etudiantCode);
    static double avoirChiffreAffaireEtablissement();
    static double calculerTotalReglementClasse(const Classe &classe);
    static Reglement rechercherReglement(const std::string &reglementId);
    static std::vector<Reglement> avoirTousReglements();
    static std::map<std::string, double> rentabiliteParFiliere();
};
