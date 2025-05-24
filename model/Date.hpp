#pragma once

#include <string>

// salim

class Date {
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
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;
};
