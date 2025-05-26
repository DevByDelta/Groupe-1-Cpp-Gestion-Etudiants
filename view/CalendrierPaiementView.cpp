#include "CalendrierPaiementView.hpp"
#include "ClasseRepository.hpp"
#include "EtudiantRepository.hpp"
#include "View.hpp"
#include "EcheancierView.hpp"

CalendrierPaiementView::CalendrierPaiementView() {}

CalendrierPaiement CalendrierPaiementView::saisir()
{
    CalendrierPaiement cp = CalendrierPaiement();
    saisirEtudiantCode(cp);
    saisirClasseId(cp);
    saisirEcheancier(cp);
    return cp;
}

void CalendrierPaiementView::saisirEtudiantCode(CalendrierPaiement& cp){
    std::string etudiantCode;
    while (true)
    {
        etudiantCode = View::promptString("Donner l'id de l'etudiant ");
        if (EtudiantRepository::exists(etudiantCode))
            break;
        View::showMessage("Erreur! L'identifiant de la'étudiant n'existe pas!");
    }
    cp.setEtudiantCode(etudiantCode);
}

void CalendrierPaiementView::saisirClasseId(CalendrierPaiement& cp){
    std::string classeId;
    while (true)
    {
        classeId = View::promptString("Donner l'id de la classe");
        if (ClasseRepository::exists(classeId))
            break;
        View::showMessage("Erreur! la classe est introuvable");
    }
    cp.setClasseId(classeId);
}

void CalendrierPaiementView::saisirEcheancier(CalendrierPaiement& cp){
    cp.setEcheancier(EcheancierView::choisir());
}
