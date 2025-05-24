#pragma once
// Etudiant.hpp  --  généré automatiquement
// Aminata
#include <string>
#include <vector>
class Etudiant {
private:
    std::string code;
    std::string nom;
    std::string prenom;
    int telephone;
    std::string email;

    std::vector<std::string> classesCode;
    std::vector<std::string> reglementsCode;
    std::vector<std::string> calendriersCode;

    bool estBoursier;
    bool estHandicape;
    bool familleNombreuse;
    bool estOrphelin;

public:
    Etudiant();
    Etudiant(const std::string& nom,
             const std::string& prenom,
             int telephone,
             const std::string& email,
             bool estBoursier = false,
             bool estHandicape = false,
             bool familleNombreuse = false,
             bool estOrphelin = false);

    const std::string& getCode() const;
    const std::string& getNom() const;
    const std::string& getPrenom() const;
    int getTelephone() const;
    const std::string& getEmail() const;

    const std::vector<std::string>& getClassesCode() const;
    const std::vector<std::string>& getReglementsCode() const;
    const std::vector<std::string>& getCalendriersCode() const;

    void setNom(const std::string& nom);
    void setPrenom(const std::string& prenom);
    void setTelephone(int tel);
    void setEmail(const std::string& mail);

    void addClasse(const std::string& codeClasse);
    void addReglement(const std::string& codeReglement);
    void addCalendrier(const std::string& codeCalendrier);

    std::string toString() const;

    ~Etudiant();
};
