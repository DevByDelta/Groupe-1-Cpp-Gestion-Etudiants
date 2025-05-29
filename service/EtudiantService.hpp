#pragma once
#include "../model/entity/Etudiant.hpp"
class EtudiantService {
private:
    EtudiantService(){};
    EtudiantService(const EtudiantService &) = delete;
    EtudiantService  &operator=(const EtudiantService &) = delete;


public:
    static EtudiantService &instance();
    void validerMetierNom(Etudiant& etudiant,const std::string& nom);
    void validerMetierPrenom(Etudiant& etudiant,const std::string& prenom);
    void validerMetierTelephone(Etudiant& etudiant,const std::string& telephone);
    void validerMetierEmail(Etudiant& etudiant,const std::string& email);
    void validerMetierClasseId(Etudiant& etudiant,const std::string& classeId);
    void validerMetierCadPaieId(Etudiant& etudiant,const std::string& cadPaieId);
    void validerMetierEstBoursier(Etudiant& etudiant, bool etat);
    void validerMetierEstHandicape(Etudiant& etudiant,bool etat);
    void validerMetierFamilleNombreuse(Etudiant& etudiant,bool etat);
    void validerMetierEstOrphelin(Etudiant& etudiant,bool etat);
    bool ajouterEtudiant(const Etudiant& etudiant);
    bool supprimerEtudiant(const std::string& code);
    Etudiant rechercherEtudiant(const std::string& code);
    bool exist(const std::string& code);
    std::vector<Etudiant> avoirTousEtudiants();
};
