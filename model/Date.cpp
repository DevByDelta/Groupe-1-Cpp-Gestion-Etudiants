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
