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
    cp.genererEcheances();
    cp.majReduction();
    cp.majMontantParEcheance();
    return cp;
}

void CalendrierPaiementView::saisirEtudiantCode(CalendrierPaiement &cp)
{
    std::string etudiantCode;
    while (true){
        try{
            etudiantCode = View::promptString("Entrer le code de l'étudiant: ");
            cp.setEtudiantCode(etudiantCode);
            break;
        }
        catch (const std::runtime_error &ex){
            View::error(std::string(ex.what()));
            View::warning("Saisir le code d'un étudiant qui exist!");
        }
    }
    cp.setEtudiantCode(etudiantCode);
}

void CalendrierPaiementView::saisirClasseId(CalendrierPaiement &cp)
{
    std::string classeId;
    while (true){
        try{
            classeId = View::promptString("Donner l'id de la classe: ");
            cp.setClasseId(classeId);
        }
        catch(const std::exception& ex){
            View::error(std::string(ex.what()));
            View::warning("Erreur lors de l'ajout de la classe!");
        }
    }
    cp.setClasseId(classeId);
}

void CalendrierPaiementView::saisirEcheancier(CalendrierPaiement &cp)
{
    cp.setEcheancier(EcheancierView::choisir());
}
