#pragma once

#include <string>
#include <vector>
#include "View.hpp"
#include "Etudiant.hpp"

class EtudiantView : public View
{
private:
    EtudiantView() {}
    EtudiantView(const EtudiantView &) = delete;
    EtudiantView &operator=(const EtudiantView &) = delete;

public:
    Etudiant input();
    static EtudiantView &instance();

     void ajouterReglementId(Etudiant etudiant);

    // méthodes de modifications
    void modifierNom(Etudiant &etu);
    void modifierPrenom(Etudiant &etu);
    void modifierTelephone(Etudiant &etu);
    void modifierEmail(Etudiant &etu);
    void modifierClasseId(Etudiant &etu);
    void modifierCadPaieId(Etudiant &etu);
    void modifierEstBoursier(Etudiant &etu);
    void modifierEstHandicape(Etudiant &etu);
    void modifierEstOrphelin(Etudiant &etu);
    void modifierFamilleNombreuse(Etudiant &etu);

    // méthodes pures services
    void saisirEtEnregistrerEtudiant();
    void supprimerEtudiant();
    void rechercherEtudiant();
    void modifierEtudiant();
    void displayAll(std::vector<Etudiant> etudiants);

    // méthodes services utiles
};
