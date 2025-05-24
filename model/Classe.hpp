#pragma once
#include<string>
#include<vector>
#include <map>
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

    
    static Classe To(const std::map<std::string, std::string>& data); // a faire
};
