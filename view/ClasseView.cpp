#include <exception>
#include <map>

#include "ClasseView.hpp"
#include "../model/entity/Classe.hpp"
#include "../service/ClasseService.hpp"


Classe ClasseView::input()
{
    Classe cl = Classe();
    modifierNom(cl, false);
    return cl;
}
void ClasseView::modifierNom(Classe &cl, bool one)
{
    do{
        std::string nom = promptString("Donner le nom de la classe: ");
        try
        {
            ClasseService::validerMetierNom(cl, nom);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }while (!one);
}
void ClasseView::modifierFormationId(Classe &cl, bool one)
{
    do{
        std::string formationId = promptString("Donner l'id de la formation: ");
        try
        {
            ClasseService::validerMetierFormationId(cl, formationId);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }while (!one);
}

void ClasseView::saisirEtEnregistrerClasse()
{
    Classe cl = input();
    if(ClasseService::enregistrerClasse(cl)){
        success("Classe bien enregistré avec l'id " + cl.getId());
    }
    else{
        error("Une erreur est survenue!");
        warning("La classe n'a pas été enregistrer");
    }
}

void ClasseView::supprimerClasse()
{
    std::string classeId = promptString("Entrer l'id de la classe: ");
    if (ClasseService::supprimerClasse(classeId))
    {

        success("Classe bien supprimer");
    }
    else
    {
        error("Erreur! la classe est introuvable");
    }
}

void ClasseView::rechercherClasse()
{
    std::string classeId = promptString("Entrer l'id de la classe: ");
    if (ClasseService::exist(classeId))
    {
        success("Classe trouvé:");
        Classe cl = ClasseService::rechercherClasse(classeId);
        showMessage(cl.toString());
    }
    else
    {
        error("Erreur! la classe est introuvable");
    }
}

void ClasseView::modifierClasse()
{
    std::string classeId = promptString("Entrer l'id de la classe: ");
    if (!ClasseService::exist(classeId))
    {
        error("Erreur! la classe est introuvable");
        return;
    }
    Classe cl = ClasseService::rechercherClasse(classeId);
    showMessage(cl.toString());
    static std::map<std::string, std::string> menuAt = {
        {"nom", "Modifier le nom"},
        {"formationId", "Modifier la formation"},
        {"addEtudiantCode", "Ajouter un etudiant"},
    };
    while (true)
    {
        std::string key = afficherMenu(menuAt, "Modifier les attributs de la classe");
        if (key == "nom")
        {
            modifierNom(cl);
            success("Le nom a été bien modifié");
        }
        else if (key == "formationId")
        {
            modifierFormationId(cl);
            success("La formation a été bien modifiée");
        }

        if (key != "quit"){
            ClasseService::enregistrerClasse(cl);
        }
        else
        {
            return;
        }
    }
}

void ClasseView::afficherEffectifClasse()
{
    std::string classeId = promptString("Entrer l'id de la classe: ");
    if (!ClasseService::exist(classeId))
    {
        error("Erreur! la classe est introuvable");
        return;
    }
    int nombreE = ClasseService::avoirEffectif(classeId);
    showMessage("Il y a " + std::to_string(nombreE) + " étudiants dans cette classe");
}

void ClasseView::afficherCoutFormationClasse()
{
    std::string classeId = promptString("Entrer l'id de la classe: ");
    if (!ClasseService::exist(classeId))
    {
        error("Erreur! la classe est introuvable");
        return;
    }
    double coutAnnuel = ClasseService::avoirCoutFormation(classeId);
    showMessage(classeId + " : " + std::to_string(coutAnnuel));
}

void ClasseView::afficherTous(){
    auto cls = ClasseService::avoirTousClasses();
    displayAll(cls);
}

void ClasseView::displayAll(std::vector<Classe> classes){
    banner("LISTES DES CLASSES");
    if (classes.empty()) {
        showMessage("Aucune classe disponible.");
        return;
    }
    for (auto r : classes){
        showStringObject(r.toString());
    }
}
