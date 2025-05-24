#pragma once
#include<string>
#include<vector>
#include "Date.hpp"
// Reglement.hpp  --  généré automatiquement
// salim

class Reglement {
private:
    std::string id;
    std::string etudiantCode;
    std::string classeId;
    Date date;
    double montant;
public:
    Reglement();
    ~Reglement();
    const std::string& getId() const;
    const std::string& getEtudiantCode() const;
    const std::string& getclasseId() const;
    const Date& getDate() const;
    void setEtudiantCode(const std::string& code);
    void setClasseId(const std::string& id);
    double getMontant()const ;
    void setMontant(double montant);
    std::string Reglement::toString() const;
    
};
