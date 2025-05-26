#include "ClasseView.hpp"
#include "Classe.hpp"
#include "FormationRepository.hpp"
#include "EtudiantRepository.hpp"
#include <string>

ClasseView::ClasseView() {}

Classe ClasseView::saisir(){
    Classe cl = Classe();

    std::string nom = View::promptString("Donner le nom de la classe");
    cl.setNom(nom);

    std::string formationId;
    while (true)
    {
        formationId = View::promptString("Donner l'id de la formation");
        if(FormationRepository::exists(formationId)) break;
        View::showMessage("Erreur! L'identifiant de la formation n'existe pas!");
    }
    cl.setFormationId(formationId);

    ajouterEtudiantCode(cl);
    return cl;
}

void ClasseView::ajouterEtudiantCode(Classe cl){
    while (View::promptYesNo("Voulez vous ajouter un étudiant?"))
    {
        std::string code = View::promptString("Saisir le code de l'étudiant");
        if(!EtudiantRepository::exists(code)){
            View::showMessage("Code invalide! Etudiant n'existe pas.");
        }
        else{
            cl.addEtudiantCode(code);
        }
    }
}
