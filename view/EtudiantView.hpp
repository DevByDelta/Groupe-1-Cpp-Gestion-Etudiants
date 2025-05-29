#pragma once

#include <string>
#include <vector>

#include "Etudiant.hpp"


class EtudiantView
{
public:
    static void ajouterReglementId(Etudiant etudiant);
    static Etudiant saisir();
    static std::string saisieClasseId();
    static std::string saisieCadPaieId();
    static void ajouterReglement(Etudiant e);
    static bool saisirEstBoursier();
    static bool saisirEstHandicape();
    static bool saisirFamilleNombreuse();
    static bool saisirEstOrphelin();
    static std::string saisirTelephone();
    static std::string saisirEmail();
    static void displayAll(std::vector<Etudiant> etudiants);
};
