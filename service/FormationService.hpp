#pragma once
#include "../model/entity/Formation.hpp"
#include  "../model/enum/Niveau.hpp"
#include <vector>
#include <string>
#include "../model/entity/Classe.hpp"
#include <map>

class FormationService {
private:
    FormationService() {}
    FormationService(const FormationService &) = delete;
    FormationService &operator=(const FormationService &) = delete;

public:
    static FormationService &instance();
    bool exist(const std::string& id);
    void validerMertierFiliere(Formation& f,const std::string& filiere);
    void validerMertierNiveau(Formation& f,const Niveau::Type& niveau);
    void validerMetierDureeAnnuelle(Formation& f, int dureeAnnuelle);
    void validerMetierCoutAnnuel(Formation& f, double coutAnnuel);
    bool ajouterFormation(const Formation& etudiant);
    bool supprimerFormation(const std::string& formationId);
    Formation rechercherFormation(const std::string& formationId);
    std::vector<Formation> avoirTousFormations();
    const std::vector<Classe>& avoirTousClasses(const std::string& formationId);
    int nombreEtudiantPourUneFormation(const std::string& formationId);
    std::pair<std::string, double> avoirFilierePlusRentable();
    Formation formationLaPlusPopulaire();
};
