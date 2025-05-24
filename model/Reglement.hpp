#pragma once
#include<string>
#include<vector>
#include <map>
#include "Date.hpp"

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
    void setEtudiantCode(const std::string& etudiantCode);
    void setClasseId(const std::string& classeId);
    double getMontant()const ;
    void setMontant(double montant);
    std::string Reglement::toString() const;
    
    static Reglement To(const std::map<std::string, std::string>& data); // a faire
};
