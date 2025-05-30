#include <exception>
#include <map>

#include "ClasseView.hpp"
#include "../model/entity/Classe.hpp"
#include "../service/ClasseService.hpp"


Classe ClasseView::input()
{
    Classe cl = Classe();
    modifierNom(cl);
    return cl;
}
void ClasseView::modifierNom(Classe &cl)
{
    while (true)
    {
        std::string nom = promptString("Donner le nom de l'étudiant: ");
        try
        {
            ClasseService::validerMetierNom(cl, nom);
            return;
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}
void ClasseView::modifierFormationId(Classe &cl)
{
    while (true)
    {
        std::string formationId = promptString("Donner l'id de la formation: ");
        try
        {
            ClasseService::validerMetierFormationId(cl, formationId);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}

void ClasseView::ajouterEtudiantCode(Classe &cl)
{
    while (promptYesNo("Voulez vous ajouter un étudiant?"))
    {
        std::string etudiantCode = promptString("Saisir le code de l'étudiant: ");
        try
        {
            ClasseService::validerMetierAddEtudiantCode(cl, etudiantCode);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}

void ClasseView::saisirEtEnregistrerClasse()
{
    Classe cl = input();
    showMessage("--- Affichage de la classe ---");
    showMessage(cl.toString());
    if(ClasseService::enregistrerClasse(cl)){
        success("Classe bien enregistré");
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
        {"retour", "retour"}
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
        else if (key == "addEtudiantCode")
        {
            ajouterEtudiantCode(cl);
            success("L'etudiant a bien été bien modifiée");
        }

        if (key != "retour"){
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
    Classe cl = ClasseService::rechercherClasse(classeId);
    int nombreE = cl.getEtudiantCodes().size();
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
    if (cls.empty()) {
        showMessage("Aucune classe disponible.");
        return;
    }
    displayAll(cls);
}

void ClasseView::displayAll(std::vector<Classe> classes){
    for (auto r : classes){
        showMessage(r.toString());
    }
}
