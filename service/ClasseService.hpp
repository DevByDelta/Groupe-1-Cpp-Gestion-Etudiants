#pragma once
#include <vector>
#include "../model/entity/Formation.hpp"
#include "../model/entity/Classe.hpp"

class ClasseService {
private:
    // méthodes utiles
    std::vector<Classe> avoirTousEtudiants();

public:
    static bool exist(const std::string& id);

    // méthodes de validation métiers
    static void validerMetierNom(Classe& classe,const std::string& nom);
    static void validerMetierFormationId(Classe& classe , const std::string& formationId);
    static void validerMetierAddEtudiantCode(Classe& classe , const std::string& code);

    // méthodes de services
    static bool enregistrerClasse(Classe& classe);
    static bool supprimerClasse(const std::string& id);
    static Classe rechercherClasse(const std::string& id);
    static double avoirCoutFormation(const std::string& id);
};
