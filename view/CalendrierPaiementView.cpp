#include "CalendrierPaiementView.hpp"
#include "View.hpp"
#include "EcheancierView.hpp"

CalendrierPaiementView::CalendrierPaiementView() {}

CalendrierPaiement CalendrierPaiementView::input()
{
    CalendrierPaiement cp = CalendrierPaiement();
    cp.setEtudiantCode(saisirEtudiantCode());
    cp.setClasseId(saisirClasseId());
    cp.setEcheancier(saisirEcheancier());
    cp.genererEcheances();
    cp.majReduction();
    cp.majMontantParEcheance();
    return cp;
}

std::string CalendrierPaiementView::saisirEtudiantCode()
{
    while (true)
    {
        std::string etudiantCode = View::promptString("Entrer le code de l'étudiant: ");
        if (EtudiantRepository::exists(etudiantCode))
            return etudiantCode;
        View::error("Etudiant CODE invalide : " + etudiantCode);
        View::warning("Saisir le code d'un étudiant qui exist!");
    }
}

std::string CalendrierPaiementView::saisirClasseId()
{
    std::string classeId;
    while (true)
    {
        std::string classeId = View::promptString("Donner l'id de la classe: ");
        if (ClasseRepository::exists(classeId))
            return classeId;
        View::error(std::string("Classe ID invalide : " + classeId));
        View::warning("Erreur lors de l'ajout de la classe!");
    }
}

Echeancier::Type CalendrierPaiementView::saisirEcheancier()
{
    return EcheancierView::choisir();
}
