#include <exception>

#include "ClasseView.hpp"
#include "Classe.hpp"
#include "ClasseService.hpp"

ClasseView::ClasseView() {}

Classe ClasseView::input()
{
    Classe cl = Classe();

    cl.setNom(promptString("Donner le nom de la classe"));
    cl.setFormationId(saisirFormationId());
    ajouterEtudiantCode(cl);
    return cl;
}

std::string ClasseView::saisirFormationId()
{
    while (true)
    {
        std::string formationId = promptString("Donner l'id de la formation: ");
        // if (FormationRepository::exists(formationId))
        //     return formationId;
        try {
            
        } catch (const std::exception& e) {
            error("Formation ID invalide : ");
        }
        warning("Erreur lors de l'ajout de la classe!");
    }
}

void ClasseView::ajouterEtudiantCode(Classe &cl)
{
    while (promptYesNo("Voulez vous ajouter un étudiant?"))
    {
        std::string etudiantCode = promptString("Saisir le code de l'étudiant: ");
        // if (EtudiantRepository::exists(etudiantCode))
        // {
        //     cl.addEtudiantCode(etudiantCode);
        //     success("Etudiant bien ajouté");
        // }
        // else
        // {
        //     error("Etudiant CODE: " + etudiantCode);
        //     warning("Erreur lors de l'ajout de l'étudiant!");
        // }
    }
}
