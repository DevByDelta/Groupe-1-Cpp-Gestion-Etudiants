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
    static void modifierNom(Etudiant &etu);
    static void modifierPrenom(Etudiant &etu);
    static void modifierTelephone(Etudiant &etu);
    static void modifierEmail(Etudiant &etu);
    static void modifierClasseId(Etudiant &etu);
    static void modifierCadPaieId(Etudiant &etu);
    static void modifierEstBoursier(Etudiant &etu);
    static void modifierEstHandicape(Etudiant &etu);
    static void modifierEstOrphelin(Etudiant &etu);
    static void modifierFamilleNombreuse(Etudiant &etu);

    // méthodes pures services
    static void saisirEtEnregistrerEtudiant();
    static void supprimerEtudiant();
    static void rechercherEtudiant();
    static void modifierEtudiant();
    static void displayAll(std::vector<Etudiant> etudiants);

    // méthodes services utiles
};
