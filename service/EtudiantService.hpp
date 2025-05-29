#pragma once
#include "Etudiant.hpp"
class EtudiantService {
public:
    EtudiantService();
    void validerMetierNom(Etudiant& etudiant,const std::string& nom);
    void validerMetierPrenom(Etudiant& etudiant,const std::string& prenom);
    void validerMetierTelephone(Etudiant& etudiant,const std::string& telephone);
    void validerMetierEmail(Etudiant& etudiant,const std::string& email);
    void validerMetierClasseId(Etudiant& etudiant,const std::string& classeId);
    void validerMetierCadPaie(Etudiant& etudiant,const std::string& cadPaie);
    void validerMetierEstBoursier(Etudiant& etudiant, bool etat);
    void validerMetierEstHandicape(Etudiant& etudiant,bool etat);
    void validerMetierEstFamilleNombreuse(Etudiant& etudiant,bool etat);
    void validerMetierEstOrphelin(Etudiant& etudiant,bool etat);
    void validerMetierAddReglementId(Etudiant& etudiant,const std::string& reglementId);
    bool ajouterEtudiant(const Etudiant& etudiant);
    bool supprimerEtudiant(const std::string& code);
    Etudiant rechercherEtudiant(const std::string& code);
    std::vector<Etudiant> avoirTousEtudiants();
};
