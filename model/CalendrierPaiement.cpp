#include "CalendrierPaiement.hpp"
#include <sstream>

CalendrierPaiement::CalendrierPaiement()
    : id(IDGenerator::generate("CP")) {}

const std::string &CalendrierPaiement::getId() const { return id; }
const std::string &CalendrierPaiement::getEtudiantCode() const { return etudiantCode; }
const std::string &CalendrierPaiement::getClasseId() const { return classeId; }
Echeancier::Type CalendrierPaiement::getEchance() const { return echance; }
const std::vector<Date> &CalendrierPaiement::getEcheances() const { return echeances; }
double CalendrierPaiement::getMontantParEcheance() const { return montantParEcheance; }
double CalendrierPaiement::getReduction() const { return reduction; }

void CalendrierPaiement::setEtudiantCode(const std::string &code) { etudiantCode = code; }
void CalendrierPaiement::setClasseId(const std::string &code) { classeId = code; }
void CalendrierPaiement::setEchance(Echeancier::Type type) {
    echance = type;
    genererEcheances();
}
void CalendrierPaiement::setMontantParEcheance(double montant) { montantParEcheance = montant; }
void CalendrierPaiement::setReduction(double reduction) { this->reduction = reduction; }

std::string CalendrierPaiement::toString() const
{
    std::string result = "CalendrierPaiement[ID: " + id +
                         ", Etudiant: " + etudiantCode +
                         ", Classe: " + classeId +
                         ", Echéancier: " + Echeancier::toString(echance) +
                         ", Montant: " + std::to_string(montantParEcheance) +
                         ", Echéances: [";

    for (size_t i = 0; i < echeances.size(); ++i)
    {
        result += echeances[i].toString();
        if (i != echeances.size() - 1)
            result += "; ";
    }

    result += "]]";
    return result;
}


void CalendrierPaiement::genererEcheances() {
    echeances.clear();

    int nombreEcheances = 1;
    int intervalleMois = 0;

    switch (echance) {
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

    Date dateActuelle = dateInscription;
    for (int i = 0; i < nombreEcheances; ++i) {
        echeances.push_back(dateActuelle);
        dateActuelle = dateActuelle.ajouterMois(intervalleMois);
    }
}
