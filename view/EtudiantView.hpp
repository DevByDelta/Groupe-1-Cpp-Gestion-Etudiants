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
    static void modifierNom(Etudiant &etu, bool one=true);
    static void modifierPrenom(Etudiant &etu, bool one=true);
    static void modifierTelephone(Etudiant &etu, bool one=true);
    static void modifierEmail(Etudiant &etu, bool one=true);
    static void modifierClasseId(Etudiant &etu, bool one=true);
    static void modifierEstBoursier(Etudiant &etu, bool one=true);
    static void modifierEstHandicape(Etudiant &etu, bool one=true);
    static void modifierEstOrphelin(Etudiant &etu, bool one=true);
    static void modifierFamilleNombreuse(Etudiant &etu, bool one=true);
    
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
