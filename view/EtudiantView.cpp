#include <algorithm>
#include <cctype>
#include "ReglementView.hpp"
#include "../service/EtudiantService.hpp"
#include "View.hpp"
#include "../model/entity/CalendrierPaiement.hpp"
#include "EtudiantView.hpp"


Etudiant EtudiantView::input()
{
    Etudiant etu = Etudiant();
    modifierNom(etu);
    modifierPrenom(etu);
    modifierTelephone(etu);
    modifierEmail(etu);
    modifierClasseId(etu);
    modifierCadPaieId(etu);
    modifierEstBoursier(etu);
    modifierEstHandicape(etu);
    modifierEstOrphelin(etu);
    modifierFamilleNombreuse(etu);
    return etu;
}

void EtudiantView::modifierNom(Etudiant &etu){
    while (true)
    {
        std::string nom = promptString("Entrer le nom de l'étudiant: ");
        try
        {
            EtudiantService::validerMetierNom(etu, nom);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}

void EtudiantView::modifierPrenom(Etudiant &etu){
    while (true)
    {
        std::string prenom = promptString("Entrer le prenom de l'étudiant: ");
        try
        {
            EtudiantService::validerMetierPrenom(etu, prenom);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}

void EtudiantView::modifierCadPaieId(Etudiant &etu)
{
    while (true)
    {
        std::string cadPaieId = promptString("Entrer l'id du calendrier: ");
        try
        {
            EtudiantService::validerMetierCadPaieId(etu, cadPaieId);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}
void EtudiantView::modifierClasseId(Etudiant &etu)
{
    while (true)
    {
        std::string classeId = promptString("Entrer l'id de la classe de l'étudiant: ");
        try
        {
            EtudiantService::validerMetierClasseId(etu, classeId);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}

void EtudiantView::modifierEstBoursier(Etudiant &etu)
{
    while (true)
    {
        bool estBoursier = promptYesNo("Est il boursier? ");
        try
        {
            EtudiantService::validerMetierEstBoursier(etu, estBoursier);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}

void EtudiantView::modifierEstHandicape(Etudiant &etu)
{

    while (true)
    {
        bool estHandicape = promptYesNo("Est il Handicapé? ");
        try
        {
            EtudiantService::validerMetierEstHandicape(etu, estHandicape);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}
void EtudiantView::modifierFamilleNombreuse(Etudiant &etu)
{
    while (true)
    {
        bool familleNombreuse = promptYesNo("est il dans une famille nombreuse ? ");
        try
        {
            EtudiantService::validerMetierFamilleNombreuse(etu, familleNombreuse);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}
void EtudiantView::modifierEstOrphelin(Etudiant &etu)

{
    while (true)
    {
        bool estOrphelin = promptYesNo("Est il Orphelin? ");
        try
        {
            EtudiantService::validerMetierEstOrphelin(etu, estOrphelin);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}

void EtudiantView::modifierTelephone(Etudiant &etu)
{
    while (true)
    {
        std::string telephone = promptString("Entrer le telephone de l'étudiant: ");
        try
        {
            EtudiantService::validerMetierTelephone(etu, telephone);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}
void EtudiantView::modifierEmail(Etudiant &etu)
{
    while (true)
    {
        std::string email = promptString("Entrer l'email de l'étudiant: ");
        try
        {
            EtudiantService::validerMetierEmail(etu, email);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}

void EtudiantView::saisirEtEnregistrerEtudiant()
{
    Etudiant etu = Etudiant();
    etu = input();
    if (EtudiantService::ajouterEtudiant(etu))
    {
        showMessage("etudiant ajouté avec succés!");
    }
    else
    {
        showMessage("erreur lors de l'ajout de l'étudiant");
    }
}

void EtudiantView::supprimerEtudiant()
{
    std::string etudiantCode = promptString("entrer le le code de l'étudiant");
    if (EtudiantService::supprimerEtudiant(etudiantCode))
    {
        showMessage("etudiant supprimé avec success");
    }
    else
    {
        showMessage("Ereur lors de la suppression de l'etudiant");
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
        showMessage("Etudiant non trouvé!");
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
        {"cadPaieId", "Modifier le calendrier de paiement"},
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
        else if (key == "cadPaieId")
        {
            modifierCadPaieId(e);
            success("l'id du calendier de paiement a été bien modifé");
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

        if (key != "retour")
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
    for (auto e : etudiants)
    {
        showMessage(e.toString());
    }
}
