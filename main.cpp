#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

#include "view/ClasseView.hpp"
#include "view/CalendrierPaiementView.hpp"
#include "view/EtudiantView.hpp"
#include "view/ReglementView.hpp"
#include "view/FormationView.hpp"
#include "view/View.hpp"

using namespace std;

static std::map<std::string, std::string> MENU_PRINCIPAL = {
    {"etudiants", "Gestion des étudiants"},
    {"classes", "Gestion des classes"},
    {"formations", "Gestion des formations"},
    {"paiements", "Gestion des paiements"},
};

static std::map<std::string, std::string> MENU_GESTION_ETUDIANT = {
    {"add", "Ajouter un étudiant"},
    {"edit", "Modifier un étudiant"},
    {"del", "Supprimer un étudiant"},
    {"find", "Rechercher un étudiant"},
    {"all", "Afficher tous les étudiants"},
    {"cadPaie", "Définir le calendrier de paiement pour un étudiant"},
};

static std::map<std::string, std::string> MENU_GESTION_PAIEMENT = {
    {"add", "Ajouter un règlement"},
    {"edit", "Modifier un règlement"},
    {"del", "Supprimer un règlement"},
    {"find", "Rechercher un règlement"},
    {"all", "Afficher tous les règlements"},
    {"forOneStudent", "Afficher les règlements pour un étudiant"},
    {"reliquat", "Afficher le reliquat d'un étudiant"},
    {"chiffre", "Afficher le chiffre d'affaires de l'établissement"},
    {"rentable", "Afficher la rentabilité par filière"},
};

static std::map<std::string, std::string> MENU_GESTION_CLASSE = {
    {"add", "Ajouter une classe"},
    {"edit", "Modifier une classe"},
    {"del", "Supprimer une classe"},
    {"find", "Rechercher une classe par ID"},
    {"all", "Afficher les classes"},
    {"effectif", "Afficher l'effectif d’une classe"},
    {"cout", "Afficher le coût de formation d’une classe"},
};

static std::map<std::string, std::string> MENU_GESTION_FORMATION = {
    {"add", "Ajouter une formation"},
    {"edit", "Modifier une formation"},
    {"del", "Supprimer une formation"},
    {"find", "Rechercher une Formation"},
    {"all", "Afficher toutes les formations"},
    {"mostRentable", "Afficher la formation la plus rentable"},
    {"mostPopulaire", "Afficher la formation la plus populaire"},
};

int main()
{
    std::string keyMain, keySec;
    while (true)
    {
        std::string keyMain = View::afficherMenu(MENU_PRINCIPAL, "Menu principal", "o", 40, "⮞  ");
        if (keyMain == "etudiants")
        {
            View::loader();
            while (true)
            {
                keySec = View::afficherMenu(MENU_GESTION_ETUDIANT, "Gestion des étudiants");
                if (keySec == "add")
                {
                    View::loader();
                    EtudiantView::saisirEtEnregistrerEtudiant();
                }
                else if (keySec == "edit")
                {
                    View::loader();
                    EtudiantView::modifierEtudiant();
                }
                else if (keySec == "del")
                {
                    View::loader();
                    EtudiantView::supprimerEtudiant();
                }
                else if (keySec == "find")
                {
                    View::loader();
                    EtudiantView::rechercherEtudiant();
                }
                else if (keySec == "all")
                {
                    View::loader();
                    EtudiantView::afficherTous();
                }
                else if (keySec == "cadPaie")
                {
                    View::loader();
                    EtudiantView::definirCadPaieId();
                }
                else
                {
                    View::countdownBar();
                    break;
                }
                system("pause");
                View::countdownBar();
            }
        }
        else if (keyMain == "classes")
        {
            View::loader();
            while (true)
            {
                keySec = View::afficherMenu(MENU_GESTION_CLASSE, "Gestion des classes", "=", 45);
                if (keySec == "add")
                {
                    View::loader();
                    ClasseView::saisirEtEnregistrerClasse();
                }
                else if (keySec == "edit")
                {
                    View::loader();
                    ClasseView::modifierClasse();
                }
                else if (keySec == "del")
                {
                    View::loader();
                    ClasseView::supprimerClasse();
                }
                else if (keySec == "find")
                {
                    View::loader();
                    ClasseView::rechercherClasse();
                }
                else if (keySec == "all")
                {
                    View::loader();
                    ClasseView::afficherTous();
                }
                else if (keySec == "effectif")
                {
                    View::loader();
                    ClasseView::afficherEffectifClasse();
                }
                else if (keySec == "cout")
                {
                    View::loader();
                    ClasseView::afficherCoutFormationClasse();
                }
                else
                {
                    View::countdownBar();
                    break;
                }
                system("pause");
                View::countdownBar();
            }
        }
        else if (keyMain == "formations")
        {
            View::loader();
            while (true)
            {
                keySec = View::afficherMenu(MENU_GESTION_FORMATION, "Gestion des formations");
                if (keySec == "add")
                {
                    View::loader();
                    FormationView::saisirEtEnregistrerFormation();
                }
                else if (keySec == "edit")
                {
                    View::loader();
                    FormationView::modifierFormation();
                }
                else if (keySec == "del")
                {
                    View::loader();
                    FormationView::supprimerFormation();
                }
                else if (keySec == "find")
                {
                    View::loader();
                    FormationView::rechercherFormation();
                }
                else if (keySec == "all")
                {
                    View::loader();
                    FormationView::afficherTousFormations();
                }
                else if (keySec == "mostRentable")
                {
                    View::loader();
                    FormationView::afficherFilierePlusRentable();
                }
                else if (keySec == "mostPopulaire")
                {
                    View::loader();
                    FormationView::afficherFormationsPopulaires();
                }
                else
                {
                    View::countdownBar();
                    break;
                }
                system("pause");
                View::countdownBar();
            }
        }
        else if (keyMain == "paiements")
        {
            View::loader();
            while (true)
            {
                keySec = View::afficherMenu(MENU_GESTION_PAIEMENT, "Gestion des paiements");
                if (keySec == "add")
                {
                    View::loader();
                    ReglementView::ajouterReglement();
                }
                else if (keySec == "edit")
                {
                    View::loader();
                    ReglementView::modifierReglement();
                }
                else if (keySec == "del")
                {
                    View::loader();
                    ReglementView::supprimerReglement();
                }
                else if (keySec == "find")
                {
                    View::loader();
                    ReglementView::rechercherReglement();
                }
                else if (keySec == "all")
                {
                    View::loader();
                    ReglementView::listerReglements();
                }
                else if (keySec == "forOneStudent")
                {
                    ReglementView::afficherReglementsEtudiantParAnnee();
                }
                else if (keySec == "reliquat")
                {
                    View::loader();
                    ReglementView::afficherReliquatEtudiant();
                }
                else if (keySec == "chiffre")
                {
                    View::loader();
                    ReglementView::afficherChiffreAffaireEtablissement();
                }
                else if (keySec == "rentable")
                {
                    View::loader();
                    ReglementView::afficherRentabiliteParFiliere();
                }
                else
                {
                    View::countdownBar();
                    break;
                }
                system("pause");
                View::countdownBar();
            }
        }
        else if (keyMain == "quit")
        {
            View::countdownBar();
            break;
        }
    };
    return 0;
}
