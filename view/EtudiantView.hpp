#pragma once

#include <string>
#include <vector>

#include "Etudiant.hpp"

class EtudiantView
{
public:
    void displayAll(std::vector<Etudiant> etudiants);
    Etudiant input();

    std::string saisieClasseId();
    std::string saisieCadPaieId();
    void ajouterReglement(Etudiant e);
    bool saisirEstBoursier();
    bool saisirEstHandicape();
    bool saisirFamilleNombreuse();
    bool saisirEstOrphelin();
    std::string saisirTelephone();
    std::string saisirEmail();
    
    void ajouterReglementId(Etudiant etudiant);
};
