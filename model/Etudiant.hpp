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
    std::string telephone;
    std::string email;
    std::string classeCode;
    std::vector<std::string> reglementsCode;
    std::string cadPaieId;

    bool estBoursier;
    bool estHandicape;
    bool familleNombreuse;
    bool estOrphelin;

public:
    Etudiant();

    const std::string& getCode() const;
    const std::string& getNom() const;
    const std::string& getPrenom() const;
    const std::string& getTelephone() const;
    const std::string& getEmail() const;

    const std::string& getClasseCode() const;
    const std::vector<std::string>& getReglementsCode() const;
    const std::string& getCadPaieId() const;

    bool getEstBoursier() const;
    bool getEstHandicape() const;
    bool getFamilleNombreuse() const;
    bool getEstOrphelin() const;

    void setNom(const std::string& nom);
    void setPrenom(const std::string& prenom);
    void setTelephone(const std::string& telephone);
    void setEmail(const std::string& email);
    
    void setEstBoursier(bool estBoursier);
    void setEstHandicape(bool estHandicape);
    void setFamilleNombreuse(bool familleNombreuse);
    void setEstOrphelin(bool estOrphelin);

    void setclasseCode(const std::string& classeCode);
    void addReglement(const std::string& reglementCode);
    void setCadPaieId(const std::string& cadPaieId);

    std::string toString() const;

};
