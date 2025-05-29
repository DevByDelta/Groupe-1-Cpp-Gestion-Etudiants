#include "ClasseView.hpp"
#include "Classe.hpp"
#include "FormationRepository.hpp"
#include "EtudiantRepository.hpp"

ClasseView::ClasseView() {}

Classe ClasseView::saisir()
{
    Classe cl = Classe();

    cl.setNom(View::promptString("Donner le nom de la classe"));
    cl.setFormationId(saisirFormationId());
    ajouterEtudiantCode(cl);
    return cl;
}

std::string ClasseView::saisirFormationId()
{
    while (true)
    {
        std::string formationId = View::promptString("Donner l'id de la formation: ");
        if (FormationRepository::exists(formationId))
            return formationId;
        View::error("Formation ID invalide : ");
        View::warning("Erreur lors de l'ajout de la classe!");
    }
}

void ClasseView::ajouterEtudiantCode(Classe &cl)
{
    while (View::promptYesNo("Voulez vous ajouter un étudiant?"))
    {
        std::string etudiantCode = View::promptString("Saisir le code de l'étudiant: ");
        if (EtudiantRepository::exists(etudiantCode))
        {
            cl.addEtudiantCode(etudiantCode);
            View::success("Etudiant bien ajouté");
        }
        else
        {
            View::error("Etudiant CODE: " + etudiantCode);
            View::warning("Erreur lors de l'ajout de l'étudiant!");
        }
    }
}
