#include "FormationService.hpp"
#include "../repository/FormationRepository.hpp"
#include "../repository/ClasseRepository.hpp"
#include <exception>
#include <stdexcept>


void FormationService::validerMertierFiliere(Formation &f, const std::string &filiere)
{
    f.setFiliere(filiere);
}
void FormationService::validerMertierNiveau(Formation &f, const Niveau::Type &niveau)
{
    f.setNiveau(niveau);
}
void FormationService::validerMetierDureeAnnuelle(Formation &f, int dureeAnnuelle)
{
    f.setDureeAnnuelle(dureeAnnuelle);
}
void FormationService::validerMetierCoutAnnuel(Formation &f, double coutAnnuel)
{
    f.setCoutAnnuel(coutAnnuel);
}

bool FormationService::ajouterFormation(const Formation &formation)
{
    return FormationRepository::save(formation);
}

bool FormationService::supprimerFormation(const std::string &formationId)
{
    return FormationRepository::remove(formationId);
}
Formation FormationService::rechercherFormation(const std::string &formationId)
{
    return FormationRepository::findById(formationId);
}
std::vector<Formation> FormationService::avoirTousFormations()
{
    return FormationRepository::findAll();
}
const std::vector<Classe>& FormationService::avoirTousClasses(const std::string& formationId){
    return ClasseRepository::findBy([&](const Classe& classe){
        return classe.getFormationId() == formationId;
    });
}
int FormationService::nombreEtudiantPourUneFormation(const std::string& formationId){
    int nbEtudiant = 0;
    for(const Classe& cl : avoirTousClasses(formationId)){
        nbEtudiant += cl.getEtudiantCodes().size();
    }
    return nbEtudiant;
}
std::pair<std::string, double> FormationService::avoirFilierePlusRentable(){

    std::map<std::string, bool> montantParFiliere;
    for(const Formation& f : FormationRepository::findAll()){
        const std::string& filiere = f.getFiliere();

        int nbEtudiant = nombreEtudiantPourUneFormation(f.getId());

        int montantToatal = f.getCoutAnnuel() * nbEtudiant;

        if(montantParFiliere.count(filiere)){
            montantParFiliere[filiere] += montantToatal;
        }
        else{
            montantParFiliere[filiere] = montantToatal;
        }
    }
    std::pair<std::string, double> max_pair = {"", 0.0};
    for (const auto& pair : montantParFiliere) {
        if (pair.second > max_pair.second) {
            max_pair = pair;
        }
    }
    return max_pair;
}
Formation FormationService::formationLaPlusPopulaire(){
    std::vector<Formation> formations = avoirTousFormations();
    std::map<Formation, int> epp;
    for(const Formation& f : avoirTousFormations()){
        if(epp.count(f)){
            epp[f] += nombreEtudiantPourUneFormation(f.getId());
        }
        else{
            epp[f] = nombreEtudiantPourUneFormation(f.getId());
        }
    }
    std::pair<Formation, double> max_pair = {Formation(), 0.0};
    for (const auto& pair : epp) {
        if (pair.second > max_pair.second) {
            max_pair = pair;
        }
    }
    return max_pair.first;
}
FormationService &FormationService::instance()
{
    static FormationService inst;
    return inst;
}

bool FormationService::exist(const std::string& id){
    return FormationService::exist(id);
}
