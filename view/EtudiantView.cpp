#include <algorithm>
#include <cctype>
#include "ReglementView.hpp"
#include "../service/EtudiantService.hpp"
#include "View.hpp"
#include "../model/entity/CalendrierPaiement.hpp"
#include "EtudiantView.hpp"
#include "CalendrierPaiementView.hpp"

Etudiant EtudiantView::input()
{
    Etudiant etu = Etudiant();
    modifierNom(etu, false);
    modifierPrenom(etu, false);
    modifierTelephone(etu, false);
    modifierEmail(etu, false);
    modifierEstBoursier(etu, false);
    modifierEstHandicape(etu, false);
    modifierEstOrphelin(etu, false);
    modifierFamilleNombreuse(etu, false);
    return etu;
}

void EtudiantView::modifierNom(Etudiant &etu, bool one)
{
    do
    {
        std::string nom = promptString("Entrer le nom de l'étudiant: ");
        try
        {
            EtudiantService::validerMetierNom(etu, nom);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    } while (!one);
}

void EtudiantView::modifierPrenom(Etudiant &etu, bool one)
{
    do
    {
        std::string prenom = promptString("Entrer le prenom de l'étudiant: ");
        try
        {
            EtudiantService::validerMetierPrenom(etu, prenom);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    } while (!one);
}

void EtudiantView::modifierClasseId(Etudiant &etu, bool one)
{
    do
    {
        std::string classeId = promptString("Entrer l'id de la classe de l'étudiant: ");
        try
        {
            EtudiantService::validerMetierClasseId(etu, classeId);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    } while (!one);
}

void EtudiantView::modifierEstBoursier(Etudiant &etu, bool one)
{
    do
    {
        bool estBoursier = promptYesNo("Est il boursier? ");
        try
        {
            EtudiantService::validerMetierEstBoursier(etu, estBoursier);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    } while (!one);
}

void EtudiantView::modifierEstHandicape(Etudiant &etu, bool one)
{

    do{
        bool estHandicape = promptYesNo("Est il Handicapé? ");
        try
        {
            EtudiantService::validerMetierEstHandicape(etu, estHandicape);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }while (!one);
}
void EtudiantView::modifierFamilleNombreuse(Etudiant &etu, bool one)
{
   do{
        bool familleNombreuse = promptYesNo("Est il dans une famille nombreuse ? ");
        try
        {
            EtudiantService::validerMetierFamilleNombreuse(etu, familleNombreuse);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }while (!one);
}
void EtudiantView::modifierEstOrphelin(Etudiant &etu, bool one)

{
    do{
        bool estOrphelin = promptYesNo("Est il Orphelin? ");
        try
        {
            EtudiantService::validerMetierEstOrphelin(etu, estOrphelin);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }while (!one);
}

void EtudiantView::modifierTelephone(Etudiant &etu, bool one)
{
    do
    {
        std::string telephone = promptString("Entrer le telephone de l'étudiant: ");
        try
        {
            EtudiantService::validerMetierTelephone(etu, telephone);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    } while (!one);
}
void EtudiantView::modifierEmail(Etudiant &etu, bool one)
{
    do
    {
        std::string email = promptString("Entrer l'email de l'étudiant: ");
        try
        {
            EtudiantService::validerMetierEmail(etu, email);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    } while (!one);
}

void EtudiantView::definirCadPaieId(){
    std::string etudiantCode = promptString("Entrer le code de l'étudiant: ");
    if (!EtudiantService::exist(etudiantCode))
    {
        error("Erreur! l'étudiant est introuvable");
        return;
    }
    Etudiant e = EtudiantService::rechercherEtudiant(etudiantCode);
    bool oui = true;
    if(e.getCadPaieId() != ""){
        oui = promptYesNo("Il y a déjà un calendrier voulez-vous le remplacer? ");
    }

    if(oui){
        Formation f = EtudiantService::avoirFormation(e);
        CalendrierPaiement cp = CalendrierPaiementView::input(e, f);
    }
}

void EtudiantView::saisirEtEnregistrerEtudiant()
{
    Etudiant etu = input();
    if (EtudiantService::ajouterEtudiant(etu))
    {
        success("Etudiant bien enregistré avec le code " + etu.getCode());
    }
    else
    {
        error("Une erreur est survenue!");
        warning("L'étudiant n'a pas été enregistrer");
    }
}

void EtudiantView::supprimerEtudiant()
{
    std::string etudiantCode = promptString("entrer le le code de l'étudiant");
    if (EtudiantService::supprimerEtudiant(etudiantCode))
    {
        success("Etudiant supprimé avec success");
    }
    else
    {
        error("Erreur lors de la suppression de l'étudiant");
    }
}
void EtudiantView::rechercherEtudiant()
{
    std::string etudiantCode = promptString("entrer le le code de l'étudiant");
    if (EtudiantService::exist(etudiantCode))
    {
        Etudiant etu = Etudiant();
        etu = EtudiantService::rechercherEtudiant(etudiantCode);
        showMessage(etu.toString());
    }
    else
    {
        error("Etudiant non trouvé!");
    }
}

void EtudiantView::modifierEtudiant()
{
    std::string etudiantCode = promptString("Entrer le code de l'étudiant: ");
    if (!EtudiantService::exist(etudiantCode))
    {
        error("Erreur! l'étudiant est introuvable");
        return;
    }

    Etudiant e = EtudiantService::rechercherEtudiant(etudiantCode);
    showMessage(e.toString());
    static std::map<std::string, std::string> menuAt = {
        {"nom", "Modifier le nom"},
        {"prenom", "Modifier le prenom"},
        {"telephone", "Modifier le telephone"},
        {"mail", "Modifier le mail"},
        {"classeId", "Modifier la classe"},
        {"estBoursier", "Modifier l'état être  boursier"},
        {"estHandicape", "Modifier l'état être  handicapé"},
        {"familleNombreuse", "Modifier l'état famille nombreuse"},
        {"estOrphelin", "Modifier l'état être orphelin"},
    };

    while (true)
    {
        std::string key = afficherMenu(menuAt, "Modifier les attributs de l'étudiant");
        if (key == "nom")
        {
            modifierNom(e);
            success("le nom a été bien modifié");
        }
        else if (key == "prenom")
        {
            modifierPrenom(e);
            success("le prenom a été bien modifié");
        }
        else if (key == "telephone")
        {
            modifierTelephone(e);
            success("le téléphone a été bien modifié");
        }
        else if (key == "mail")
        {
            modifierEmail(e);
            success("le mail a été bien modifié");
        }
        else if (key == "classeId")
        {
            modifierClasseId(e);
            success("l'id de la classe a été bien modifié");
        }
        else if (key == "estBoursier")
        {
            modifierEstBoursier(e);
            success("l'état de l'étudiant a été bien modifié");
        }
        else if (key == "estHandicape")
        {
            modifierEstHandicape(e);
            success("l'état de l'étudiant a été bien modifié");
        }
        else if (key == "familleNombreuse")
        {
            modifierFamilleNombreuse(e);
            success("l'état de l'étudiant a été bien modifié");
        }
        else if (key == "estOrphelin")
        {
            modifierEstOrphelin(e);
            success("l'état de l'étudiant a été bien modifié");
        }

        if (key != "quit")
        {
            EtudiantService::ajouterEtudiant(e);
        }
        else
        {
            return;
        }
    }
}

void EtudiantView::displayAll(std::vector<Etudiant> etudiants)
{
    banner("LISTES DES ETUDIANTS");
    if (etudiants.empty())
    {
        showMessage("Aucun étudiant disponible.");
        return;
    }
    for (auto e : etudiants)
    {
        showStringObject(e.toString());
    }
}

void EtudiantView::afficherTous()
{
    auto ets = EtudiantService::avoirTousEtudiants();
    displayAll(ets);
}

