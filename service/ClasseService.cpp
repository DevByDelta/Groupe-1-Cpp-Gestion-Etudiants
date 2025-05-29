#include <exception>

#include "ClasseService.hpp"
#include "../repository/FormationRepository.hpp"
#include "../repository/ClasseRepository.hpp"
#include <exception>
#include <stdexcept>


ClasseService::ClasseService() {}

void ClasseService::validerMetierNom(Classe& classe,const  std::string& nom){
    classe.setNom(nom);
}

void ClasseService::validerMetierFormationId(Classe& classe,const  std::string& formationId){
    if (!FormationRepository::exists(formationId)){
        throw std::runtime_error("Formation ID invalide"+ formationId);
    }
    classe.setNom(formationId);
}

void ClasseService::validerMetierAddEtudiantCode(Classe& classe , const std::string& code){
    classe.addEtudiantCode(code);
}

bool ClasseService::enregistrerClasse(Classe& classe){
    return ClasseRepository::save(classe);
}
bool ClasseService::supprimerClasse(const std::string& id){
    return ClasseRepository::remove(id);
}
Classe ClasseService::rechercherClasse(const std::string& id){
    return ClasseRepository::findById(id);
}
std::vector<Classe> ClasseService::avoirTousEtudiants(){
    return ClasseRepository::findAll();
}
double ClasseService::avoirCoutFormation(const std::string& id){
    Classe cl = ClasseRepository::findById(id);
    std::string formationId = cl.getFormationId();
    Formation f = FormationRepository::findById(formationId);
    return f.getCoutAnnuel();
}
ClasseService &ClasseService::instance()
{
    static ClasseService inst;
    return inst;
}

bool ClasseService::exist(const std::string& id){
    return ClasseService::exist(id);
}
