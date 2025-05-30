#pragma once
#include "../model/entity/Etudiant.hpp"
class EtudiantService {
private:

public:
    static void validerMetierNom(Etudiant& etudiant,const std::string& nom);
    static void validerMetierPrenom(Etudiant& etudiant,const std::string& prenom);
    static void validerMetierTelephone(Etudiant& etudiant,const std::string& telephone);
    static void validerMetierEmail(Etudiant& etudiant,const std::string& email);
    static void validerMetierClasseId(Etudiant& etudiant,const std::string& classeId);
    static void validerMetierCadPaieId(Etudiant& etudiant,const std::string& cadPaieId);
    static void validerMetierEstBoursier(Etudiant& etudiant, bool etat);
    static void validerMetierEstHandicape(Etudiant& etudiant,bool etat);
    static void validerMetierFamilleNombreuse(Etudiant& etudiant,bool etat);
    static void validerMetierEstOrphelin(Etudiant& etudiant,bool etat);
    static bool ajouterEtudiant(const Etudiant& etudiant);
    static bool supprimerEtudiant(const std::string& code);
    static Etudiant rechercherEtudiant(const std::string& code);
    static bool exist(const std::string& code);
    static std::vector<Etudiant> avoirTousEtudiants();
};
