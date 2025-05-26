#pragma once

#include <string>
#include <vector>
#include <map>

#include "Date.hpp"
#include "Echeancier.hpp"
#include "IDGenerator.hpp"

#include "Etudiant.hpp"
#include "EtudiantRepository.hpp"

class CalendrierPaiement {
private:
    std::string id;
    std::string etudiantCode;
    std::string classeId;
    Date dateInscription;
    Echeancier::Type echeancier;
    std::vector<Date> echeances;
    double reduction;
    double montantParEcheance;

    void genererEcheances();

    void setId(const std::string& id);
    void setDateInscription(const Date& dateInscription);
    void setEcheances(const std::vector<Date>& echeances);

    // méthodes de calculs
    double calculReduction(const Etudiant& e);
    double calculMontantParEcheance(const Etudiant& e);

public:
    CalendrierPaiement();

    // Accesseurs
    const std::string& getId() const;
    const std::string& getEtudiantCode() const;
    const std::string& getClasseId() const;
    const Date& getDateInscription() const;
    Echeancier::Type getEcheancier() const;
    const std::vector<Date>& getEcheances() const;
    double getMontantParEcheance() const;
    double getReduction() const;

    // Mutateurs
    void setEtudiantCode(const std::string& code);
    void setClasseId(const std::string& code);
    void setEcheancier(Echeancier::Type type);
    void setMontantParEcheance(double montant);
    void setReduction(double reduction);
    void addEcheance(const Date& d);

    // Méthode d'affichage
    std::string toString() const;

    // Sérialisation
    std::string toTxt() const;
    static CalendrierPaiement To(const std::map<std::string, std::string>& data);
};
