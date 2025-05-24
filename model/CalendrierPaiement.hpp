#pragma once

#include <string>
#include <vector>
#include "Date.hpp"
#include "Echeancier.hpp"
#include "IDGenerator.hpp"
#include <map>

class CalendrierPaiement {
private:
    std::string id;
    std::string etudiantCode;
    std::string classeId;
    Date dateInscription;
    Echeancier::Type echance;
    std::vector<Date> echeances;
    double reduction;
    double montantParEcheance;

    void genererEcheances();

public:
    CalendrierPaiement();

    // Accesseurs
    const std::string& getId() const;
    const std::string& getEtudiantCode() const;
    const std::string& getClasseId() const;
    Date getDateInscription() const;
    Echeancier::Type getEchance() const;
    const std::vector<Date>& getEcheances() const;
    double getMontantParEcheance() const;
    double getReduction() const;

    // Mutateurs
    void setEtudiantCode(const std::string& code);
    void setClasseId(const std::string& code);
    void setEchance(Echeancier::Type type);
    void setMontantParEcheance(double montant);
    void setReduction(double reduction);

    // Méthode d'affichage
    std::string toString() const;

    static CalendrierPaiement To(const std::map<std::string, std::string>& data); // a faire
};
