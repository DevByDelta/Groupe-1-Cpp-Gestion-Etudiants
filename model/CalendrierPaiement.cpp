#include <sstream>

#include "CalendrierPaiement.hpp"
#include "pathsConst.hpp"
#include "Etudiant.hpp"
#include "Classe.hpp"

#include "EtudiantRepository.hpp"
#include "ClasseRepository.hpp"
#include "FormationRepository.hpp"

#include "ReflectionMacros.hpp"
#include "reductionsConst.hpp"

// Constructeur
CalendrierPaiement::CalendrierPaiement()
{
    id = IDGenerator::generate("CP");
    dateInscription = Date();
    echeancier = Echeancier::Type::Invalide;
    reduction = -1;

}

// Getters
const std::string &CalendrierPaiement::getId() const
{
    return id;
}

const std::string &CalendrierPaiement::getEtudiantCode() const
{
    return etudiantCode;
}

const std::string &CalendrierPaiement::getClasseId() const
{
    return classeId;
}

const Date &CalendrierPaiement::getDateInscription() const
{
    return dateInscription;
}

Echeancier::Type CalendrierPaiement::getEcheancier() const
{
    return echeancier;
}

const std::vector<Date> &CalendrierPaiement::getEcheances() const
{
    return echeances;
}

double CalendrierPaiement::getMontantParEcheance() const
{
    return montantParEcheance;
}
void CalendrierPaiement::setMontantParEcheance(double montantParEcheance)
{
    this->montantParEcheance = montantParEcheance;
}
void CalendrierPaiement::majMontantParEcheance(){
    if (reduction == -1){
        throw std::runtime_error("Reduction non initialisée");
    }
    if (!ClasseRepository::exists(classeId)){
        throw std::runtime_error("Classe ID invalide : " + classeId);
    }
    std::string formationId = ClasseRepository::findById(classeId).getFormationId();
    if (FormationRepository::exists(formationId)){
        throw std::runtime_error("Formation ID invalide : " + formationId);
    }
    double montantFor = FormationRepository::findById(formationId).getCoutAnnuel();
    montantParEcheance = montantFor * (1 - reduction);
}

double CalendrierPaiement::getReduction() const
{
    return reduction;
}
void CalendrierPaiement::setReduction(double reduction)
{
    this->reduction = reduction;
}
void CalendrierPaiement::majReduction(){
    if (!EtudiantRepository::exists(etudiantCode)){
        throw std::runtime_error("Etudiant CODE invalide : " + etudiantCode);
    }
    Etudiant e = EtudiantRepository::findById(etudiantCode);
    reduction = (e.getEstBoursier()) ? RD_BOURSIER : 0
                + (e.getEstHandicape()) ? RD_HANDICAPE : 0
                + (e.getFamilleNombreuse()) ? RD_FAMILLE_NOMBREUSE : 0
                + (e.getEstOrphelin()) ? RD_ORPHELIN : 0;
}


// Setters
void CalendrierPaiement::setId(const std::string &id)
{
    this->id = id;
}

void CalendrierPaiement::setEtudiantCode(const std::string &etudiantCode)
{
    if (!EtudiantRepository::exists(etudiantCode))
    {
        throw std::runtime_error("Etudiant CODE invalide : " + etudiantCode);
    }
    this->etudiantCode = etudiantCode;
}

void CalendrierPaiement::setClasseId(const std::string &classeId)
{
    if (!ClasseRepository::exists(classeId))
    {
        throw std::runtime_error("Classe ID invalide : " + classeId);
    }
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

std::string CalendrierPaiement::toTxt() const
{
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
