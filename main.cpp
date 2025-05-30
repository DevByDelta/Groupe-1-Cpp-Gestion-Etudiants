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
#include <windows.h>

using namespace std;

static std::map<std::string, std::string> MENU_PRINCIPAL = {
    {"etudiants", "Gestion des étudiants"},
    {"classes", "Gestion des classes"},
    {"formations", "Gestion des formations"},
    {"paiements", "Gestion des paiements"},
    {"quit", "Quitter"}};

static std::map<std::string, std::string> MENU_GESTION_ETUDIANT = {
    {"add", "Ajouter un étudiant"},
    {"edit", "Modifier un étudiant"},
    {"del", "Supprimer un étudiant"},
    {"find", "Rechercher un étudiant"},
    {"all", "Afficher tous les étudiants"},
    {"back", "Retour"}
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
    {"back", "Retour"}
};

static std::map<std::string, std::string> MENU_GESTION_CLASSE = {
    {"add",      "Ajouter une classe"},
    {"edit",     "Modifier une classe"},
    {"del",      "Supprimer une classe"},
    {"find",     "Rechercher une classe par ID"},
    {"all",      "Afficher les classes"},
    {"effectif", "Afficher l'effectif d’une classe"},
    {"cout",     "Afficher le coût de formation d’une classe"},
    {"back",     "Retour"}
};

static std::map<std::string, std::string> MENU_GESTION_FORMATION = {
    {"add", "Ajouter une formation"},
    {"edit", "Modifier une formation"},
    {"del", "supprimer une formation"},
    {"find", "Rechercher une Formation"},
    {"all","Afficher toutes les formations"},
    {"mostRentable","Afficher la formation la plus rentable"},
    {"mostPopulaire","Afficher la formation la plus populaire"},
    {"back", "Retour"}};

int main()
{
    SetConsoleTitle("NeoCoder");
    std::string keyMain, keySec;
    while (true)
    {
        std::string keyMain = View::afficherMenu(MENU_PRINCIPAL, "Menu principal", "*", 40, ">");

        if(keyMain == "etudiants"){
            while (true)
            {
                keySec = View::afficherMenu(MENU_GESTION_ETUDIANT, "Gestion des étudiants");
                if (keySec == "add"){
                    EtudiantView::saisirEtEnregistrerEtudiant();
                }
                else if(keySec == "edit"){
                    EtudiantView::modifierEtudiant();
                }
                else if(keySec == "del"){
                    EtudiantView::supprimerEtudiant();
                }
                else if(keySec == "find"){
                    EtudiantView::rechercherEtudiant();
                }
                else if(keySec == "all"){
                    EtudiantView::afficherTous();
                }
                else{
                    break;
                }
                system("pause");
            }

        }
        else if (keyMain == "classes"){
            while (true)
            {
                keySec = View::afficherMenu(MENU_GESTION_CLASSE, "Gestion des classes");
                if (keySec == "add"){
                    ClasseView::saisirEtEnregistrerClasse();
                }
                else if(keySec == "edit"){
                    ClasseView::modifierClasse();
                }
                else if(keySec == "del"){
                    ClasseView::supprimerClasse();
                }
                else if(keySec == "find"){
                    ClasseView::rechercherClasse();
                }
                else if(keySec == "all"){
                    ClasseView::afficherTous();
                }
                else if(keySec == "effectif"){
                    ClasseView::afficherEffectifClasse();
                }
                else if(keySec == "cout"){
                    ClasseView::afficherCoutFormationClasse();
                }
                else{
                    break;
                }
                system("pause");
            }

        }
        else if (keyMain == "formations"){
            while (true)
            {
                keySec = View::afficherMenu(MENU_GESTION_FORMATION, "Gestion des formations");
                if (keySec == "add"){
                    FormationView::saisirEtEnregistrerFormation();
                }
                else if(keySec == "edit"){
                    FormationView::modifierFormation();
                }
                else if(keySec == "del"){
                    FormationView::supprimerFormation();
                }
                else if(keySec == "find"){
                    FormationView::rechercherFormation();
                }
                else if(keySec == "all"){
                    FormationView::afficherTousFormations();
                }
                else if(keySec == "mostRentable"){
                    FormationView::afficherFilierePlusRentable();
                }
                else if(keySec == "mostPopulaire"){
                    FormationView::afficherFormationsPopulaires();
                }
                else{
                    break;
                }
                system("pause");
            }

        }
        else if (keyMain == "paiements"){
            while(true){
                keySec = View::afficherMenu(MENU_GESTION_PAIEMENT, "Gestion des paiements");
                if (keySec == "add"){
                    ReglementView::ajouterReglement();
                }
                else if(keySec == "edit"){
                    ReglementView::modifierReglement();
                }
                else if(keySec == "del"){
                    ReglementView::supprimerReglement();
                }
                else if(keySec == "find"){
                    ReglementView::rechercherReglement();
                }
                else if(keySec == "all"){
                    ReglementView::listerReglements();
                }
                else if(keySec == "forOneStudent"){
                    ReglementView::afficherReglementsEtudiantParAnnee();
                }
                else if(keySec == "reliquat"){
                    ReglementView::afficherReliquatEtudiant();
                }
                else if(keySec == "chiffre"){
                    ReglementView::afficherChiffreAffaireEtablissement();
                }
                else if(keySec == "rentable"){
                    ReglementView::afficherRentabiliteParFiliere();
                }
                else{
                    break;
                }
                system("pause");
            }
        }
        else if (keyMain == "quit")
        {
            break;
        }
    };
    return 0;
}
