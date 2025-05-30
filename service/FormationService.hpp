#pragma once
#include "../model/entity/Formation.hpp"
#include  "../model/enum/Niveau.hpp"
#include <vector>
#include <string>
#include "../model/entity/Classe.hpp"
#include <map>

class FormationService {
public:

    static bool exist(const std::string& id);
    static void validerMertierFiliere(Formation& f,const std::string& filiere);
    static void validerMertierNiveau(Formation& f,const Niveau::Type& niveau);
    static void validerMetierDureeAnnuelle(Formation& f, int dureeAnnuelle);
    static void validerMetierCoutAnnuel(Formation& f, double coutAnnuel);
    static bool ajouterFormation(const Formation& etudiant);
    static bool supprimerFormation(const std::string& formationId);
    static  Formation rechercherFormation(const std::string& formationId);
    static std::vector<Formation> avoirTousFormations();
    static std::vector<Classe> avoirTousClasses(const std::string& formationId);
    static int nombreEtudiantPourUneFormation(const std::string& formationId);
    static std::pair<std::string, double> avoirFilierePlusRentable();
    static Formation formationLaPlusPopulaire();
};
