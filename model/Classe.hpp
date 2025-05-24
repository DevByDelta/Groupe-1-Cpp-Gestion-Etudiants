#pragma once
// Classe.hpp  --  généré automatiquement
// Kiné
#include<string>
#include<vector>
class Classe {
private:
    std::string id;
    std::string nom;
    std::string formationId;
    std::vector<std::string>etudiantCodes;
public:
    Classe();
    const std::string& getId() const ;
    const std::string& getNom() const ;
    const std::string& getFormationId() const;
    void setNom(const std::string& nom);
   void setFormationId(const std::string& formationId);
    const std::vector<std::string> getEtudiantCodes()const;
    std::string toString() const;
    void addEtudiant(const std::string& codeEtudiant);
};
