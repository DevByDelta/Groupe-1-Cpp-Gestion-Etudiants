#pragma once

#include <string>
#include <vector>
#include <map>

class Classe {
private:
    std::string id;
    std::string nom;
    std::string formationId;
    std::vector<std::string> etudiantCodes;

    void setId(const std::string& id);
    void setEtudiantCodes(const std::vector<std::string>& codes);

public:
    Classe();

    // Getters
    const std::string& getId() const;
    const std::string& getNom() const;
    const std::string& getFormationId() const;
    const std::vector<std::string>& getEtudiantCodes() const;

    // Setters métier (publics)
    void setNom(const std::string& nom);
    void setFormationId(const std::string& formationId);
    void addEtudiant(const std::string& codeEtudiant);

    // Affichage
    std::string toString() const;

    // === Sauvegarde & Chargement ===
    // Sérialisation au format texte (fichier)
    std::string toTxt() const;
    // Reconstruction depuis une map<string, string> (chargement)
    static Classe To(const std::map<std::string, std::string>& data);
};
