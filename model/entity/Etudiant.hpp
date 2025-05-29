#pragma once

#include <string>
#include <vector>
#include <map>

class Etudiant {
private:
    std::string code;
    std::string nom;
    std::string prenom ;
    std::string telephone;
    std::string email;
    std::string classeId;
    std::vector<std::string> reglementsId;
    std::string cadPaieId;

    bool estBoursier=false;
    bool estHandicape=false;
    bool familleNombreuse=false;
    bool estOrphelin=false;

    void setCode(const std::string& code);

public:
    Etudiant();

    // Getters
    const std::string& getCode() const;
    const std::string& getNom() const;
    const std::string& getPrenom() const;
    const std::string& getTelephone() const;
    const std::string& getEmail() const;
    const std::string& getClasseId() const;
    const std::vector<std::string>& getReglementsId() const;
    const std::string& getCadPaieId() const;

    bool getEstBoursier() const;
    bool getEstHandicape() const;
    bool getFamilleNombreuse() const;
    bool getEstOrphelin() const;

    // Setters métier
    void setNom(const std::string& nom);
    void setPrenom(const std::string& prenom);
    void setTelephone(const std::string& telephone);
    void setEmail(const std::string& email);

    void setEstBoursier(bool estBoursier);
    void setEstHandicape(bool estHandicape);
    void setFamilleNombreuse(bool familleNombreuse);
    void setEstOrphelin(bool estOrphelin);

    void setClasseId(const std::string& classeId);
    void addReglementId(const std::string& reglementId);
    void setCadPaieId(const std::string& cadPaieId);

    // Affichage & sérialisation
    std::string toString() const;

    // === Sauvegarde & Chargement ===
    std::string toTxt() const;
    static Etudiant To(const std::map<std::string, std::string>& data);
};
