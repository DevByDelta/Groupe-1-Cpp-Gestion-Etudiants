#pragma once

#include <string>
#include <vector>
#include <map>

class Classe {
private:
    std::string id;
    std::string nom;
    std::string formationId;

    void setId(const std::string& id);

public:
    Classe(std::string formationId = "");

    // Getters
    const std::string& getId() const;
    const std::string& getNom() const;
    const std::string& getFormationId() const;

    // Setters métier (publics)
    void setNom(const std::string& nom);
    void setFormationId(const std::string& formationId);

    // Affichage
    std::string toString() const;

    // === Sauvegarde & Chargement ===
    // Sérialisation au format texte (fichier)
    std::string toTxt() const;
    // Reconstruction depuis une map<string, string> (chargement)
    static Classe To(const std::map<std::string, std::string>& data);
};
