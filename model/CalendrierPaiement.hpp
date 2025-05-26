#pragma once

#include <string>
#include <vector>
#include <map>

#include "Date.hpp"
#include "Echeancier.hpp"
#include "IDGenerator.hpp"

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
    CalendrierPaiement();

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
    void majReduction();
    void majMontantParEcheance();


    // Méthode d'affichage
    std::string toString() const;

    // Sérialisation
    std::string toTxt() const;
    static CalendrierPaiement To(const std::map<std::string, std::string> &data);
};
