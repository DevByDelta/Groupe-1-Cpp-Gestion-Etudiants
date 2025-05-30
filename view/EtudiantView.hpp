#pragma once

#include <string>
#include <vector>
#include "View.hpp"
#include "../model/entity/Etudiant.hpp"

class EtudiantView : public View
{
public:
    static Etudiant input();

    static void ajouterReglementId(Etudiant etudiant);

    // méthodes de modifications
    static bool modifierNom(Etudiant &etu, bool one=true);
    static bool modifierPrenom(Etudiant &etu, bool one=true);
    static bool modifierTelephone(Etudiant &etu, bool one=true);
    static bool modifierEmail(Etudiant &etu, bool one=true);
    static bool modifierClasseId(Etudiant &etu, bool one=true);
    static bool modifierEstBoursier(Etudiant &etu, bool one=true);
    static bool modifierEstHandicape(Etudiant &etu, bool one=true);
    static bool modifierEstOrphelin(Etudiant &etu, bool one=true);
    static bool modifierFamilleNombreuse(Etudiant &etu, bool one=true);
    
    static void definirCadPaieId();
    // méthodes pures services
    static void saisirEtEnregistrerEtudiant();
    static void supprimerEtudiant();
    static void rechercherEtudiant();
    static void modifierEtudiant();
    static void displayAll(std::vector<Etudiant> etudiants);
    static void afficherTous();

    // méthodes services utiles
};
