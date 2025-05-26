#include "EtudiantView.hpp"
#include "View.hpp"
#include "ReglementRepository.hpp"
#include "CalendrierPaiementRepository.hpp"
#include "ClasseRepository.hpp"

EtudiantView::EtudiantView() {}

EtudiantView::~EtudiantView() {}
Etudiant EtudiantView::saisir(){
    Etudiant etu = Etudiant();

    std::string nom = View::promptString("Donner le nom de l'étudiant");
    etu.setNom(nom);
    std::string prenom = View::promptString("Donner le prenom de l'étudiant");
    etu.setPrenom(prenom);
    std::string telephone = View::promptString("Donner le télephone de l'étudiant");
    etu.setTelephone(telephone);
    std::string mail = View::promptString("Donner le mail de l'étudiant");
    etu.setEmail(mail);

    std::string classeId;
    while (true)
    {
        classeId = View::promptString("Donner l'id de la classe");
        if(ClasseRepository::exists(classeId)) break;
        View::showMessage("Erreur! L'identifiant de la classe n'existe pas!");
    }
    etu.setClasseId(classeId);
    std::string cadPaieId;
    while (true)
    {
        cadPaieId = View::promptString("Donner l'id du calendrier de paiement");
        if(CalendrierPaiementRepository::exists(cadPaieId)) break;
        View::showMessage("Erreur! L'identifiant de la classe n'existe pas!");
    }
    etu.setCadPaieId(cadPaieId);

    EtudiantView::ajouterReglementId(etu);
    
    return etu;
}

void EtudiantView::ajouterReglementId(Etudiant etudiant){
 while (View::promptYesNo("Voulez vous ajouter un réglementt?"))
    {
        std::string reglementId = View::promptString("Saisir l'id du réglement");
        if(!ReglementRepository::exists(reglementId)){
            View::showMessage("Code invalide! ce reglement  n'existe pas.");
        }
        else{
            etudiant.addReglementId(reglementId);
        }
    }
}
