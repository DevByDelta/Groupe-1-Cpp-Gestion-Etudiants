#include <algorithm>
#include <cctype>

#include "EtudiantView.hpp"
#include "View.hpp"
#include "ReglementRepository.hpp"
#include "CalendrierPaiementRepository.hpp"
#include "ClasseRepository.hpp"

EtudiantView::EtudiantView() {}

EtudiantView::~EtudiantView() {}

Etudiant EtudiantView::input()
{
    Etudiant etu = Etudiant();
    etu.setNom(View::promptString("entrer le nom de l'etudiant"));
    etu.setPrenom(View::promptString("entrer le prenom"));
    etu.setCadPaieId(saisieCadPaieId());
    etu.setClasseId(saisieClasseId());
    return etu;
}

std::string EtudiantView::saisieCadPaieId()
{
    while (true)
    {
        std::string cadPaieId = View::promptString("Entrer l'id du calendrier: ");
        if (CalendrierPaiementRepository::exists(cadPaieId))
            return cadPaieId;
        View::error("Calendrier CODE invalide : " + cadPaieId);
        View::warning("Saisir l'id d'un calendrier qui exist!");
    }
}
std::string EtudiantView::saisieClasseId()
{
    while (true)
    {
        std::string classeId = View::promptString("Entrer l'id de la classe: ");
        if (ClasseRepository::exists(classeId))
            return classeId;
        View::error("Classe CODE invalide : " + classeId);
        View::warning("Saisir l'id d'une classe qui exist!");
    }
}

void EtudiantView::ajouterReglement(Etudiant e)
{
    while (View::promptYesNo("Voulez vous ajouter un reglement?"))
    {
        std::string rgId = View::promptString("Saisir l'identifiant du reglement: ");
        if (ReglementRepository::exists(rgId))
        {
            e.addReglementId(rgId);
            View::success("Etudiant bien ajouté");
        }
        else
        {
            View::error("Etudiant CODE: " + rgId);
            View::warning("Erreur lors de l'ajout de l'étudiant!");
        }
    }
}

bool EtudiantView::saisirEstBoursier()
{
    return View::promptYesNo("Est il boursier? ");
}
bool EtudiantView::saisirEstHandicape()
{
    return View::promptYesNo("Est il Handicapé? ");
}
bool EtudiantView::saisirFamilleNombreuse()
{
    return View::promptYesNo("Est il dans une famille nombreuse? ");
}
bool EtudiantView::saisirEstOrphelin()
{
    return View::promptYesNo("Est il Orphelin? ");
}

std::string EtudiantView::saisirTelephone()
{
    while (true)
    {
        std::string telephone = View::promptString("Saisir le numéro : ");

        if (telephone.size() != 9 || !std::all_of(telephone.begin(), telephone.end(), ::isdigit))
        {
            View::error("Le numéro de téléphone doit contenir exactement 9 chiffres.");
        }
        else
        {
            return telephone;
        }
    }
}

std::string EtudiantView::saisirEmail()
{
}

void EtudiantView::displayAll(std::vector<Etudiant> etudiants)
{
    for (auto e : etudiants)
    {
    View::showMessage(e.toString());
    }
}