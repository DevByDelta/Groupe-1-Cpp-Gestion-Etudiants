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
double ReglementService::calculerTotalReglementClasse(const Classe &classe)
{
    double total = 0.0;
    for (const std::string &codeEtudiant : classe.getEtudiantCodes())
    {
        total += calculerReglementTotalEtudiant(codeEtudiant);
    }
    return total;
}

double ReglementService::avoirChiffreAffaireEtabilissement()
{
    double chiffreAffaire = 0.0;

    std::vector<Classe> classes = ClasseRepository::findAll();

    for (const Classe &classe : classes)
    {
        chiffreAffaire += calculerTotalReglementClasse(classe);
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
    auto classes = ClasseRepository::findAll();
    for (const auto &cl : classes)
    {
        const Formation &formation = FormationRepository::findById(cl.getFormationId());
        double ca = calculerTotalReglementClasse(cl);
        revenueParFiliere[formation.getFiliere()] += ca;
    }
    return revenueParFiliere;
}


bool ReglementService::exist(const std::string& id){
    return ReglementService::exist(id);
}
