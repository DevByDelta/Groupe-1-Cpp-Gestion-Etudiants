#include <sstream>
#include <exception>

#include "CalendrierPaiement.hpp"
#include "pathsConst.hpp"
#include "Etudiant.hpp"

#include "ReflectionMacros.hpp"
#include "reductionsConst.hpp"

// Constructeur
CalendrierPaiement::CalendrierPaiement(){
    this->id = IDGenerator::generate("CP");
    this->dateInscription = Date();
    this->echeancier = Echeancier::Type::Invalide;
    this->reduction = -1;
    this->etudiantCode="";
    this->classeId="";
    this->montantParEcheance=0;
}

// Getters
const std::string &CalendrierPaiement::getId() const
{
    return this->id;
}
const std::string &CalendrierPaiement::getEtudiantCode() const
{
    return this->etudiantCode;
}
const std::string &CalendrierPaiement::getClasseId() const
{
    return this->classeId;
}
const Date &CalendrierPaiement::getDateInscription() const
{
    return this->dateInscription;
}
Echeancier::Type CalendrierPaiement::getEcheancier() const
{
    return this->echeancier;
}
const std::vector<Date> &CalendrierPaiement::getEcheances() const
{
    return this->echeances;
}
double CalendrierPaiement::getMontantParEcheance() const
{
    return this->montantParEcheance;
}
double CalendrierPaiement::getReduction() const
{
    return this->reduction;
}

// Setters
void CalendrierPaiement::setId(const std::string &id)
{
    this->id = id;
}
void CalendrierPaiement::setEtudiantCode(const std::string &etudiantCode)
{
    this->etudiantCode = etudiantCode;
}
void CalendrierPaiement::setClasseId(const std::string &classeId)
{
    this->classeId = classeId;
}
void CalendrierPaiement::setDateInscription(const Date &dateInscription)
{
    this->dateInscription = dateInscription;
}
void CalendrierPaiement::setEcheancier(Echeancier::Type echeancier)
{
    if (echeancier != Echeancier::Type::Invalide)
        throw std::logic_error("Déjà initialisé.");
    this->echeancier = echeancier;
}
void CalendrierPaiement::setReduction(double reduction)
{
    if(reduction<0){
        throw std::runtime_error("La réduction doit être positif");
    }
    this->reduction = reduction;
}
void CalendrierPaiement::setMontantParEcheance(double montantParEcheance)
{
    this->montantParEcheance = montantParEcheance;
}


// maj des valeurs
void CalendrierPaiement::majReduction(const Etudiant& e){
    reduction = (e.getEstBoursier()) ? RD_BOURSIER : 0
                + (e.getEstHandicape()) ? RD_HANDICAPE : 0
                + (e.getFamilleNombreuse()) ? RD_FAMILLE_NOMBREUSE : 0
                + (e.getEstOrphelin()) ? RD_ORPHELIN : 0;
}
void CalendrierPaiement::majMontantParEcheance(double coutAnnuel){
    if(coutAnnuel<0){
        throw std::runtime_error("Le cout annuel de la formation doit être positif");
    }
    else if(this->reduction == -1){
        throw std::runtime_error("La reduction doit être initialisée");
    }
    else if(this->echeancier == Echeancier::Type::Invalide){
        throw std::logic_error("Echeancier non initialisé!");
    }

    int nombreEcheances = 1;
    switch (echeancier){
    case Echeancier::Type::EnUneFois:
        nombreEcheances = 1;
        break;
    case Echeancier::Type::Mensuel:
        nombreEcheances = 12;
        break;
    case Echeancier::Type::Trimestriel:
        nombreEcheances = 4;
        break;
    case Echeancier::Type::Semestriel:
        nombreEcheances = 2;
        break;
    default:
        return;
    }

    this->montantParEcheance = coutAnnuel / nombreEcheances * (1 - reduction);
}
// Génération des échéances en fonction de l’échéancier
void CalendrierPaiement::genererEcheances()
{
    if (echeancier == Echeancier::Type::Invalide)
        throw std::logic_error("Echeancier non initialisé!");
    if (echeances.empty())
        throw std::logic_error("Déjà initialisé!");
    echeances.clear();

    int nombreEcheances = 1;
    int intervalleMois = 0;

    switch (echeancier)
    {
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
    for (int i = 0; i < nombreEcheances; ++i)
    {
        echeances.push_back(d);
        d = d.ajouterMois(intervalleMois);
    }
}

// ajout dans une liste
void CalendrierPaiement::addEcheance(const Date &d)
{
    echeances.push_back(d);
}

// Affichage
std::string CalendrierPaiement::toString() const
{
    std::ostringstream oss;
    oss << "CalendrierPaiement[ID: " << id
        << ", Etudiant: " << etudiantCode
        << ", Classe: " << classeId
        << ", Echéancier: " << Echeancier::toString(echeancier)
        << ", Montant: " << montantParEcheance
        << ", Réduction: " << (reduction * 100) << "%"
        << ", Echéances: [";

    for (size_t i = 0; i < echeances.size(); ++i)
    {
        oss << echeances[i].toString();
        if (i != echeances.size() - 1)
            oss << ", ";
    }

    oss << "]]";
    return oss.str();
}


std::string CalendrierPaiement::toTxt() const{
    std::ostringstream oss;
    oss << "Id=" << id << "\n";
    oss << "EtudiantCode=" << etudiantCode << "\n";
    oss << "ClasseId=" << classeId << "\n";
    oss << "DateInscription=" << dateInscription.toString() << "\n";
    oss << "Echeancier=" << Echeancier::toString(echeancier) << "\n";
    oss << "MontantParEcheance=" << montantParEcheance << "\n";
    oss << "Reduction=" << reduction << "\n";

    oss << "Echeances=";
    for (size_t i = 0; i < echeances.size(); ++i)
    {
        oss << echeances[i].toString();
        if (i != echeances.size() - 1)
            oss << ",";
    }
    oss << "\n";

    return oss.str();
}

CalendrierPaiement CalendrierPaiement::To(const std::map<std::string, std::string> &data)
{
    CalendrierPaiement obj;

    SET_STRING(data, obj, Id);
    SET_STRING(data, obj, EtudiantCode);
    SET_STRING(data, obj, ClasseId);
    SET_DATE(data, obj, DateInscription);
    SET_ENUM(data, obj, Echeancier, Echeancier);
    SET_DOUBLE(data, obj, MontantParEcheance);
    SET_DOUBLE(data, obj, Reduction);
    SET_LIST_DATE(data, obj, Echeances, addEcheance);
    return obj;
}
