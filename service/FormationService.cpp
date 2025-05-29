#include "FormationService.hpp"
#include "FormationRepository.hpp"

void FormationService::validerMertierFiliere(Formation& f,const std::string& filiere){
    f.setFiliere(filiere);
}
void FormationService::validerMertierNiveau(Formation& f,const Niveau::Type& niveau){
    f.setNiveau(niveau);
}
void FormationService::validerMetierDureeAnnuelle(Formation& f, int dureeAnnuelle){
    f.setDureeAnnuelle(dureeAnnuelle);
}
void FormationService::validerMetierCoutAnnuel(Formation& f, double coutAnnuel){
    f.setCoutAnnuel(coutAnnuel);
}


bool FormationService::ajouterFormation(const Formation& formation){
    return (FormationRepository::save(formation));
    
}

bool FormationService::supprimerFormation(const std::string& formationId){
    return FormationRepository::remove(formationId);
}
Formation FormationService::rechercherFormation(const std::string& formationId){
     return FormationRepository::findById(formationId);
}
std::vector<Formation> FormationService::avoirTousFormations(){
    return FormationRepository::findAll();
}
