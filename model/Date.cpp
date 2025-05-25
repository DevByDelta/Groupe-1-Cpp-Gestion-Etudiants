#include "Date.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>

// Salim

// Date actuelle
Date::Date() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    jour = now->tm_mday;
    mois = now->tm_mon + 1;
    annee = now->tm_year + 1900;
}

// Date personnalisée
Date::Date(int j, int m, int a) : jour(j), mois(m), annee(a) {}

// Accesseurs
int Date::getJour() const { return jour; }
int Date::getMois() const { return mois; }
int Date::getAnnee() const { return annee; }

// Format : jj-mm-aaaa
std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << jour << "-"
        << std::setw(2) << mois << "-"
        << annee;
    return oss.str();
}

// Comparaison
bool Date::operator==(const Date& other) const {
    return jour == other.jour && mois == other.mois && annee == other.annee;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (annee != other.annee) return annee < other.annee;
    if (mois != other.mois) return mois < other.mois;
    return jour < other.jour;
}

bool Date::operator<=(const Date& other) const {
    return *this < other || *this == other;
}

bool Date::operator>(const Date& other) const {
    return !(*this <= other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

// Fonction auxiliaire
static bool estBissextile(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}

static int joursDansMois(int mois, int annee) {
    static const int joursParMois[] = { 31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31 };
    if (mois == 2 && estBissextile(annee))
        return 29;
    return joursParMois[mois - 1];
}

// Retourne une nouvelle date après ajout de nbJours
Date Date::ajouterJours(int nbJours) const {
    int j = jour;
    int m = mois;
    int a = annee;

    while (nbJours > 0) {
        int nbJoursDansMois = joursDansMois(m, a);
        int resteMois = nbJoursDansMois - j;

        if (nbJours <= resteMois) {
            j += nbJours;
            break;
        } else {
            nbJours -= (resteMois + 1);
            j = 1;
            m++;
            if (m > 12) {
                m = 1;
                a++;
            }
        }
    }

    return Date(j, m, a);
}

Date Date::ajouterMois(int nbMois) const {
    int nouveauMois = mois + nbMois;
    int nouvelleAnnee = annee + (nouveauMois - 1) / 12;
    nouveauMois = ((nouveauMois - 1) % 12) + 1;

    int maxJours = joursDansMois(nouveauMois, nouvelleAnnee);
    int nouveauJour = std::min(jour, maxJours);

    return Date(nouveauJour, nouveauMois, nouvelleAnnee);
}

// Conversion
Date Date::fromString(const std::string& str) {
    int j = 1, m = 1, a = 1900;
    char delim1, delim2;
    std::istringstream iss(str);
    // On s'attend à "jj-mm-aaaa"
    if (iss >> j >> delim1 >> m >> delim2 >> a) {
        if (delim1 == '-' && delim2 == '-') {
            return Date(j, m, a);
        }
    }
    // Si erreur, retourne une date par défaut (ou tu peux lever une exception si tu veux)
    return Date();
}
