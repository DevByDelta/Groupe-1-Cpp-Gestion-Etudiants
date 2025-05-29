#include "EtudiantService.hpp"
#include "ClasseRepository.hpp"
#include "EtudiantRepository.hpp"
#include <exception>

EtudiantService::EtudiantService() {}

void EtudiantService::validerMetierNom(Etudiant &etudiant, const std::string &nom)
{
    etudiant.setNom(nom);
}
void EtudiantService::validerMetierPrenom(Etudiant &etudiant, const std::string &prenom)
{
    etudiant.setPrenom(prenom);
}
void EtudiantService::validerMetierTelephone(Etudiant &etudiant, const std::string &telephone)
{
    etudiant.setTelephone(telephone);
}
void EtudiantService::validerMetierEmail(Etudiant &etudiant, const std::string &email)
{
    etudiant.setEmail(email);
}
void EtudiantService::validerMetierClasseId(Etudiant &etudiant, const std::string &classeId)
{
    if (!ClasseRepository::exists(classeId))
    {
        throw std::runtime_error("Classe ID invalide" + classeId);
    }
    etudiant.setClasseId(classeId);
}

void EtudiantService::validerMetierEstBoursier(Etudiant &etudiant, bool etat)
{
    etudiant.setEstBoursier(etat);
}
void EtudiantService::validerMetierEstHandicape(Etudiant &etudiant, bool etat)
{
    etudiant.setEstHandicape(etat);
}
void EtudiantService::validerMetierEstFamilleNombreuse(Etudiant &etudiant, bool etat)
{
    etudiant.setFamilleNombreuse(etat);
}
void EtudiantService::validerMetierEstOrphelin(Etudiant &etudiant, bool etat)
{
    etudiant.setEstOrphelin(etat);
}

void EtudiantService::validerMetierAddReglementId(Etudiant &etudiant, const std::string &reglementId)
{
    etudiant.addReglementId(reglementId);
}

bool EtudiantService::ajouterEtudiant(const Etudiant& etudiant){
    return (EtudiantRepository::save(etudiant));
    
}
bool EtudiantService::supprimerEtudiant(const std::string& code){
        return EtudiantRepository::remove(code);
}

Etudiant EtudiantService::rechercherEtudiant(const std::string& code){
    return EtudiantRepository::findById(code);
}

std::vector<Etudiant> EtudiantService::avoirTousEtudiants(){
    return EtudiantRepository::findAll();
}