#include <stdexcept>
#include "ReglementView.hpp"
#include "../service/ReglementService.hpp"
#include "../service/EtudiantService.hpp"

Reglement ReglementView::input()
{
    Reglement r = Reglement();
    modifierClasseId(r, false);
    modifierEtudiantCode(r, false);
    modifierMontant(r, false);
    return r;
}

void ReglementView::modifierEtudiantCode(Reglement &reglement, bool one)
{
    do{
        std::string code = promptString("Donner le code de l'étudiant pour ce règlement: ");
        try
        {
            ReglementService::validerMetierEtudiantCode(reglement, code);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }while (!one);
}

void ReglementView::modifierMontant(Reglement &reglement, bool one)
{
    do{
        double montant = promptDouble("Donner le montant du règlement: ");
        try
        {
            ReglementService::validerMetierMontant(reglement, montant);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }while (!one);
}
void ReglementView::modifierClasseId(Reglement &reglement, bool one)
{
    
    do{
        std::string nouvelleId = View::promptString("Entrer le nouvel ID de la classe associée :");
        try
        {
            ReglementService::validerMetierClasseId(reglement, nouvelleId);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }while (!one);
}
void ReglementView::ajouterReglement()
{
    Reglement r = input();
    if(ReglementService::ajouterReglement(r)){
        success("Règlement bien enregistré avec l'id " + r.getId());
    }
    else{
        error("Une erreur est survenue!");
        warning("Le règlement n'a pas été enregistrer");
    }
}
void ReglementView::modifierReglement()
{
    std::string regId = promptString("Entrer l'id du règlement: ");
    if (!ReglementService::exist(regId))
    {
        error("Erreur ! Le règlement est introuvable");
        return;
    }

    Reglement r = ReglementService::rechercherReglement(regId);
    showMessage(r.toString());

    static const std::map<std::string, std::string> menuAt = {
        {"etudiantCode", "Modifier le code étudiant"},
        {"classeId", "Modifier l'id de la classe"},
        {"montant", "Modifier le montant"},
    };

    while (true)
    {
        std::string key = afficherMenu(menuAt, "Modifier les attributs du règlement");
        if (key == "etudiantCode")
        {
            modifierEtudiantCode(r);
            success("Le code étudiant a été modifié");
        }
        else if (key == "classeId")
        {
            modifierClasseId(r);
            success("L'id de la classe a été modifié");
        }
        else if (key == "montant")
        {
            modifierMontant(r);
            success("Le montant a été modifié");
        }

        if (key != "quit")
        {
            ReglementService::ajouterReglement(r);
        }
        else
        {
            return;
        }
    }
}
void ReglementView::supprimerReglement()
{
    std::string regId = promptString("Entrer l'id du règlement : ");
    if (ReglementService::supprimerReglement(regId))
    {
        success("Règlement bien supprimé");
    }
    else
    {
        error("Erreur ! Le règlement est introuvable");
    }
}
void ReglementView::rechercherReglement()
{
    std::string reglementId = promptString("Entrer l'id du règlement: ");
    if (ReglementService::exist(reglementId))
    {
        success("Règlement trouvé :");
        Reglement r = ReglementService::rechercherReglement(reglementId);
        showMessage(r.toString());
    }
    else
    {
        error("Erreur ! Le règlement est introuvable");
    }
}
void ReglementView::listerReglements()
{
    auto regs = ReglementService::avoirTousReglements();
    displayAll(regs);
}

void ReglementView::displayAll(std::vector<Reglement> reglements)
{
    banner("LISTES DES FORMATIONS");
    if (reglements.empty())
    {
        showMessage("Aucun règlement disponible.");
        return;
    }
    for (auto r : reglements)
    {
        showMessage(r.toString());
    }
}

void ReglementView::afficherReglementsEtudiantParAnnee()
{
    std::string code = promptString("Entrer le code de l'étudiant : ");
    if (!EtudiantService::exist(code))
    {
        error("Erreur ! Cet étudiant est introuvable");
        return;
    }
    auto regs = ReglementService::avoirTousReglementPourUnEtudiant(code);
    displayAll(regs);
}

void ReglementView::afficherReliquatEtudiant()
{
    std::string etudiantCode = promptString("Entrer le code de l'étudiant : ");
    if (EtudiantService::exist(etudiantCode))
    {
        double reliquat = ReglementService::avoirReliquatEtudiant(etudiantCode);
        showMessage("Reliquat à payer : " + std::to_string(reliquat));
    }
    else
    {
        showMessage("Aucun étudiant correspondant à ce code n' a été trouvé");
    }
}

void ReglementView::afficherChiffreAffaireEtablissement()
{
    double chiffreAffaire = ReglementService::avoirChiffreAffaireEtablissement();
    showMessage("Le chiffre d'affaire de l'établissement est : " + std::to_string(chiffreAffaire));
}

void ReglementView::afficherRentabiliteParFiliere()
{
    auto m = ReglementService::rentabiliteParFiliere();
    for (const auto &p : m)
    {
        showMessage(p.first + " : " + std::to_string(p.second));
    }
}
