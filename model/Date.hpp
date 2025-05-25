#pragma once

#include <string>

// salim

class Date
{
private:
    int jour;
    int mois;
    int annee;

public:
    // Constructeurs
    Date();
    Date(int j, int m, int a);

    // Accesseurs
    int getJour() const;
    int getMois() const;
    int getAnnee() const;

    // Affichage format jj-mm-aaaa
    std::string toString() const;

    // Opérateurs de comparaison
    bool operator==(const Date &other) const;
    bool operator!=(const Date &other) const;
    bool operator<(const Date &other) const;
    bool operator<=(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator>=(const Date &other) const;

    // Méthodes utiles
    Date ajouterJours(int nbJours) const;
    Date ajouterMois(int nbMois) const;

    // Méthode de convertion
    static Date fromString(const std::string& str);
};
