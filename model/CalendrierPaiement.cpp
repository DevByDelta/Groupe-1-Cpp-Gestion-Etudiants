#include "CalendrierPaiement.hpp"
#include "ReflectionMacros.hpp"
#include <sstream>

// Constructeur
CalendrierPaiement::CalendrierPaiement()
    : id(IDGenerator::generate("CP")) {}

// Getters
const std::string& CalendrierPaiement::getId() const {
    return id;
}

const std::string& CalendrierPaiement::getEtudiantCode() const {
    return etudiantCode;
}

const std::string& CalendrierPaiement::getClasseId() const {
    return classeId;
}

const Date& CalendrierPaiement::getDateInscription() const {
    return dateInscription;
}

Echeancier::Type CalendrierPaiement::getEcheancier() const {
    return echeancier;
}

const std::vector<Date>& CalendrierPaiement::getEcheances() const {
    return echeances;
}

double CalendrierPaiement::getMontantParEcheance() const {
    return montantParEcheance;
}

double CalendrierPaiement::getReduction() const {
    return reduction;
}

// Setters
void CalendrierPaiement::setId(const std::string& id) {
    this->id = id;
}

void CalendrierPaiement::setEtudiantCode(const std::string& code) {
    etudiantCode = code;
}

void CalendrierPaiement::setClasseId(const std::string& code) {
    classeId = code;
}

void CalendrierPaiement::setDateInscription(const Date& dateInscription) {
    this->dateInscription = dateInscription;
}

void CalendrierPaiement::setEcheancier(Echeancier::Type type) {
    echeancier = type;
    genererEcheances();
}

void CalendrierPaiement::setEcheances(const std::vector<Date>& echeances) {
    this->echeances = echeances;
}

void CalendrierPaiement::addEcheance(const Date& d) {
    echeances.push_back(d);
}

void CalendrierPaiement::setMontantParEcheance(double montant) {
    montantParEcheance = montant;
}

void CalendrierPaiement::setReduction(double reduction) {
    this->reduction = reduction;
}

// Affichage
std::string CalendrierPaiement::toString() const {
    std::ostringstream oss;
    oss << "CalendrierPaiement[ID: " << id
        << ", Etudiant: " << etudiantCode
        << ", Classe: " << classeId
        << ", Echéancier: " << Echeancier::toString(echeancier)
        << ", Montant: " << montantParEcheance
        << ", Réduction: " << (reduction * 100) << "%"
        << ", Echéances: [";

    for (size_t i = 0; i < echeances.size(); ++i) {
        oss << echeances[i].toString();
        if (i != echeances.size() - 1)
            oss << ", ";
    }

    oss << "]]";
    return oss.str();
}

// Génération des échéances en fonction de l’échéancier
void CalendrierPaiement::genererEcheances() {
    echeances.clear();

    int nombreEcheances = 1;
    int intervalleMois = 0;

    switch (echeancier) {
        case Echeancier::Type::EnUneFois:
            nombreEcheances = 1;
            intervalleMois = 0;
            break;
        case Echeancier::Type::Mensuel:
            nombreEcheances = 12;
            intervalleMois = 1;
            break;
        case Echeancier::Type::Trimestriel:
            nombreEcheances = 4;
            intervalleMois = 3;
            break;
        case Echeancier::Type::Semestriel:
            nombreEcheances = 2;
            intervalleMois = 6;
            break;
        default:
            return;
    }

    Date d = dateInscription;
    for (int i = 0; i < nombreEcheances; ++i) {
        echeances.push_back(d);
        d = d.ajouterMois(intervalleMois);
    }
}

std::string CalendrierPaiement::toTxt() const {
    std::ostringstream oss;
    oss << "Id=" << id << "\n";
    oss << "EtudiantCode=" << etudiantCode << "\n";
    oss << "ClasseId=" << classeId << "\n";
    oss << "DateInscription=" << dateInscription.toString() << "\n";
    oss << "Echeancier=" << Echeancier::toString(echeancier) << "\n";
    oss << "MontantParEcheance=" << montantParEcheance << "\n";
    oss << "Reduction=" << reduction << "\n";

    oss << "Echeances=";
    for (size_t i = 0; i < echeances.size(); ++i) {
        oss << echeances[i].toString();
        if (i != echeances.size() - 1) oss << ",";
    }
    oss << "\n";

    return oss.str();
}
