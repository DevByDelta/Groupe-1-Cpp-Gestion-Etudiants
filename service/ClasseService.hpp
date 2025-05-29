#pragma once
#include <vector>
#include "../model/entity/Formation.hpp"
#include "../model/entity/Classe.hpp"

class ClasseService {
private:
    ClasseService() {}
    ClasseService(const ClasseService &) = delete;
    ClasseService &operator=(const ClasseService &) = delete;

    // méthodes utiles
    std::vector<Classe> avoirTousEtudiants();

public:
    static ClasseService &instance();
    bool exist(const std::string& id);

    // méthodes de validation métiers
    void validerMetierNom(Classe& classe,const std::string& nom);
    void validerMetierFormationId(Classe& classe , const std::string& formationId);
    void validerMetierAddEtudiantCode(Classe& classe , const std::string& code);

    // méthodes de services
    bool enregistrerClasse(Classe& classe);
    bool supprimerClasse(const std::string& id);
    Classe rechercherClasse(const std::string& id);
    double avoirCoutFormation(const std::string& id);
};
