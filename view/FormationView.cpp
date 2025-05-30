#include "FormationView.hpp"
#include "../service/FormationService.hpp"
#include "NiveauView.hpp"

Formation FormationView::input()
{
    Formation f =Formation();
    modifierFiliere(f);
    modifierNiveau(f);
    modifierDureeAnnuelle(f);
    modifierCoutAnnuel(f);
    return f;
}

void FormationView::modifierFiliere(Formation &formation)
{
    while (true)
    {
        std::string filiere = promptString("Donner la filiere: ");
        try
        {
            FormationService:: validerMertierFiliere(formation, filiere);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}
void FormationView::modifierNiveau(Formation &formation)
{
    while (true)
    {
        Niveau::Type niveau = NiveauView::choisir();
        try
        {
            FormationService:: validerMertierNiveau(formation, niveau);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}
void FormationView::modifierDureeAnnuelle(Formation& formation)
{
    while (true)
    {
        int duree = promptInt("Donner la durée annuelle (en heures): ");
        try
        {
            FormationService::validerMetierDureeAnnuelle(formation, duree);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}
void FormationView::modifierCoutAnnuel(Formation& formation)
{
    while (true)
    {
        double coutAnnuel = promptDouble("Donner le coût annuel");
        try
        {
            FormationService::validerMetierCoutAnnuel(formation, coutAnnuel);
        }
        catch (const std::exception &e)
        {
            error(e.what());
        }
    }
}
void FormationView::saisirEtEnregistrerFormation() {
    Formation f = input();
    FormationService::ajouterFormation(f);
}
void FormationView::supprimerFormation() {
    std::string formId = promptString("Entrer l'id de la formation : ");
    if (FormationService::supprimerFormation(formId)) {
        success("Formation bien supprimée");
    } else {
        error("Erreur ! La formation est introuvable");
    }
}
void FormationView::rechercherFormation() {
    std::string formationId = promptString("Entrer l'id de la formation: ");
    if (FormationService::exist(formationId)) {
        success("Formation trouvée :");
        Formation f = FormationService::rechercherFormation(formationId);
        showMessage(f.toString());
    } else {
        error("Erreur ! La formation est introuvable");
    }
}
void FormationView::modifierFormation()
{
    std::string formId = promptString("Entrer l'id de la formation: ");
    if (!FormationService::exist(formId))
    {
        error("Erreur ! La formation est introuvable");
        return;
    }

    Formation f = FormationService::rechercherFormation(formId);
    showMessage(f.toString());

    static const std::map<std::string,std::string> menuAt = {
        {"filiere", "Modifier la filière"},
        {"niveau",  "Modifier le niveau"},
        {"duree",   "Modifier la durée annuelle"},
        {"cout",    "Modifier le coût annuel"},
        {"retour",  "Retour"}
    };

    while (true)
    {
        std::string key = afficherMenu(menuAt, "Modifier les attributs de la formation");
        if (key == "filiere")
        {
            modifierFiliere(f);
            success("La filière a été modifiée");
        }
        else if (key == "niveau")
        {
            modifierNiveau(f);
            success("Le niveau a été modifié");
        }
        else if (key == "duree")
        {
            modifierDureeAnnuelle(f);
            success("La durée annuelle a été modifiée");
        }
        else if (key == "cout")
        {
            modifierCoutAnnuel(f);
            success("Le coût annuel a été modifié");
        }

        if (key != "retour")
        {
            FormationService::ajouterFormation(f);
        }
        else
        {
            return;
        }
    }
}

void FormationView::displayAll(std::vector<Formation> formations)
{
    for (auto f : formations)
{
    showMessage(f.toString());
    }
}

void FormationView::afficherFilierePlusRentable()
{
    auto p = FormationService::avoirFilierePlusRentable();
    showMessage("Filière la plus rentable : " + p.first + " - CA : " + std::to_string(p.second));
}

void FormationView::afficherFormationsPopulaires()
{
    auto f = FormationService::formationLaPlusPopulaire();
    showMessage("Formation la plus populaire : " + f.getFiliere() + " (ID : " + f.getId() + ")");
}

void FormationView::afficherTousFormations(){
    std::vector<Formation> formations = FormationService::avoirTousFormations();
    displayAll(formations);
}
