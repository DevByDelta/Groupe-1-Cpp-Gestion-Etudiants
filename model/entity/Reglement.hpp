#pragma once

#include <string>
#include <vector>
#include <map>

#include "../utils/Date.hpp"

class Reglement {
private:
    std::string id;
    std::string etudiantCode;
    std::string classeId;
    Date date;
    double montant;

    void setId(const std::string& id);
    void setDate(const Date& date);

public:
    Reglement();

    // Getters
    const std::string& getId() const;
    const std::string& getEtudiantCode() const;
    const std::string& getClasseId() const;
    const Date& getDate() const;
    double getMontant() const;

    // Setters métier
    void setEtudiantCode(const std::string& etudiantCode);
    void setClasseId(const std::string& classeId);
    void setMontant(double montant);

    // Affichage
    std::string toString() const;

    // === Sauvegarde & Chargement ===
    std::string toTxt() const;
    static Reglement To(const std::map<std::string, std::string>& data);
};
