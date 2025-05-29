#pragma once
#include <vector>
#include "Formation.hpp"
#include "Classe.hpp"

class ClasseService {
public:
    ClasseService();
    void validerMetierNom(Classe& classe,const std::string& nom);
    void validerMetierFormationId(Classe& classe , const std::string& formationId);
    void validerMetierAddEtudiantCode(Classe& classe , const std::string& code);
    bool ajouterClasse(Classe& classe);
    bool supprimerClasse(const std::string& id);
    Classe rechercherClasse(const std::string& id);
    std::vector<Classe> avoirTousEtudiants();
    double avoirCoutFormation(const std::string& id);
};
