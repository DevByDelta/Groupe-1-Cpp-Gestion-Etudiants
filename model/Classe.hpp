#pragma once
// Classe.hpp  --  généré automatiquement
// Kiné
#include<string>
#include<vector>
class Classe {
private:
    std::string id;
    std::string nom;
    int idFormation;
    std::vector <std::string>etudiantCodes;
public:
    Classe();
    ~Classe();
    const std::string& getId() const ;
    const std::string& getNom() const ;
    void setNom(const std::string& nom);
   int getIdFormation() const;
    const std::vector<std::string> getEtudiantCodes()const ;
    std::string toString() const;
};
