#pragma once

#include <string>
#include <vector>
#include <map>

#include "../utils/Date.hpp"
#include "../enum/Echeancier.hpp"
#include "../utils/IDGenerator.hpp"
#include "Formation.hpp"
#include "Etudiant.hpp"

class CalendrierPaiement
{
private:
    std::string id;
    std::string etudiantCode;
    std::string classeId;
    Date dateInscription;
    Echeancier::Type echeancier;
    std::vector<Date> echeances;
    double reduction;
    double montantParEcheance;

    void setId(const std::string &id);
    void setDateInscription(const Date &dateInscription);
    void setReduction(double reduction);
    void setMontantParEcheance(double montantParEcheance);

    // Fonctions d'ajout
    void addEcheance(const Date &d);

public:
    CalendrierPaiement(
        const std::string& etudiantCode = "",
        const std::string& classeId = ""
    );

    // Accesseurs
    const std::string &getId() const;
    const std::string &getEtudiantCode() const;
    const std::string &getClasseId() const;
    const Date &getDateInscription() const;
    Echeancier::Type getEcheancier() const;
    const std::vector<Date> &getEcheances() const;
    double getMontantParEcheance() const;
    double getReduction() const;

    // Mutateurs
    void setEtudiantCode(const std::string &etudiantCode);
    void setClasseId(const std::string &classeId);
    void setEcheancier(Echeancier::Type echeancier);

    // méthodes de mise à jours d'attributs dépendant
    void genererEcheances();
    void majReduction(const Etudiant &e);
    void majMontantParEcheance(const Formation& f);


    // Méthode d'affichage
    std::string toString() const;

    // Sérialisation
    std::string toTxt() const;
    static CalendrierPaiement To(const std::map<std::string, std::string> &data);
};
