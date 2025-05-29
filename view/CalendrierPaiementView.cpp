#include "CalendrierPaiementView.hpp"
#include "View.hpp"
#include "EcheancierView.hpp"
#include "CalendrierPaiementService.hpp"

CalendrierPaiementView::CalendrierPaiementView() {}

CalendrierPaiement CalendrierPaiementView::input(const Etudiant& e, const Formation& f)
{
    CalendrierPaiement cp = CalendrierPaiement();
    modifierClasseId(cp);
    modifierEtudiantCode(cp);
    modifierEcheancier(cp);
    cp.genererEcheances();
    cp.majReduction(e);
    cp.majMontantParEcheance(f);
    return cp;
}

void CalendrierPaiementView::modifierEtudiantCode(CalendrierPaiement &cp)
{
    while (true)
    {
        std::string etudiantCode = promptString("Entrer le code de l'étudiant: ");
        try
        {
            CalendrierPaiementService::instance().validerMetierEtudiantCode(cp, etudiantCode);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}

void CalendrierPaiementView::modifierClasseId(CalendrierPaiement &cp)
{
    while (true)
    {
        std::string classeId = promptString("Donner l'id de la classe: ");
        try
        {
            CalendrierPaiementService::instance().validerMetierClasseId(cp, classeId);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}

void CalendrierPaiementView::modifierEcheancier(CalendrierPaiement &cp)
{
    while (true)
    {
        Echeancier::Type echeancier = EcheancierView::instance().choisir();
        try
        {
            CalendrierPaiementService::instance().validerMetierEchancier(cp, echeancier);
        }
        catch(const std::exception& e)
        {
            error(e.what());
        }
        
    }
}

CalendrierPaiementView &CalendrierPaiementView::instance()
{
    static CalendrierPaiementView inst;
    return inst;
}