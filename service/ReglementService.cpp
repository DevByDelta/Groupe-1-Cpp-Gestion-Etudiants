#include "ReglementService.hpp"
#include "../repository/EtudiantRepository.hpp"
#include "../repository/ClasseRepository.hpp"
#include "../model/entity/Reglement.hpp"
#include "../repository/ReglementRepository.hpp"
#include "../model/entity/Formation.hpp"
#include "../repository/FormationRepository.hpp"
#include "../model/utils/Date.hpp"
#include <exception>
#include <stdexcept>


void ReglementService::validerMetierEtudiantCode(Reglement &r, const std::string &code)
{
    if (!EtudiantRepository::exists(code))
    {
        throw std::runtime_error("Code étudiant invalide : " + code);
    }
    r.setEtudiantCode(code);
}
void ReglementService::validerMetierClasseId(Reglement &r, const std::string &classeId)
{
    if (!ClasseRepository::exists(classeId))
    {
        throw std::runtime_error("Classe ID invalide : " + classeId);
    }
    r.setClasseId(classeId);
}
void ReglementService::validerMetierMontant(Reglement &r, double montant)
{
    r.setMontant(montant);
}
bool ReglementService::ajouterReglement(const Reglement &reglement)
{
    return ReglementRepository::save(reglement);
}
bool ReglementService::supprimerReglement(const std::string reglementId)
{
    return ReglementRepository::remove(reglementId);
}
// à verifier
std::vector<Reglement> ReglementService::avoirTousReglementPourUnEtudiant(const std::string &etudiantCode)
{
    int annee = Date::giveAnnee();
    Date dateDebut = Date(1, 9, annee);
    Date dateFin = Date(1, 6, annee + 1);
    std::vector<Reglement> result = ReglementRepository::findBy([&](const Reglement &reglement)
                                                                { return reglement.getEtudiantCode() == etudiantCode && dateDebut <= reglement.getDate() && reglement.getDate() <= dateFin; });
    return result;
}

double ReglementService::calculerReglementTotalEtudiant(const std::string &etudiantCode)
{
    std::vector<Reglement> reglements = avoirTousReglementPourUnEtudiant(etudiantCode);

    Etudiant etudiant = EtudiantRepository::findById(etudiantCode);
    double total = 0.0;
    for (const Reglement &r : reglements)
    {
        total += r.getMontant();
    }

    return total;
}

double ReglementService::avoirReliquatEtudiant(const std::string &etudiantCode)
{
    Etudiant etudiant = EtudiantRepository::findById(etudiantCode);
    Classe classe = ClasseRepository::findById(etudiant.getClasseId());
    Formation formation = FormationRepository::findById(classe.getFormationId());

    double totalReglement = calculerReglementTotalEtudiant(etudiantCode);
    return formation.getCoutAnnuel() - totalReglement;
}

double ReglementService::avoirChiffreAffaireEtablissement()
{
    double chiffreAffaire = 0.0;
    for (const Reglement &r : ReglementRepository::findAll())
    {
        chiffreAffaire += r.getMontant();
    }
    return chiffreAffaire;
}

std::vector<Reglement> ReglementService::avoirTousReglements()
{
    return ReglementRepository::findAll();
}
Reglement ReglementService::rechercherReglement(const std::string &reglementId)
{
    return ReglementRepository::findById(reglementId);
}
std::map<std :: string,double> ReglementService::rentabiliteParFiliere()
{
    std::map<std::string, double> revenueParFiliere;
    for (const auto &r : ReglementRepository::findAll())
    {
        auto cl = ClasseRepository::findById(r.getClasseId());
        auto f = FormationRepository::findById(cl.getFormationId());
        auto filiere = f.getFiliere();
        if(revenueParFiliere.count(filiere)){
            revenueParFiliere[filiere] += r.getMontant();
        }
        else{
            revenueParFiliere[filiere] = r.getMontant();
        }
    }
    return revenueParFiliere;
}


bool ReglementService::exist(const std::string& id){
    return ReglementRepository::exists(id);
}
