#include "ReglementView.hpp"
#include "IDGenerator.hpp"
#include"View.hpp"
#include"EtudiantRepository.hpp"
#include "ClasseRepository.hpp"

ReglementView::ReglementView() {}

Reglement ReglementView::saisir() {
    Reglement obj;
    // Génération automatique de l'ID
    obj.setId(IDGenerator::generate("RE"));

    // Saisie des champs
    std::string etuCode = View::promptString("Donner le code de l'etudiant : ");
    obj.setEtudiantCode(etuCode);

    std::string classeId = View::promptString("Donner l'id de la classe : ");
    obj.setClasseId(classeId);

    Date date = View::promptDate("Donner la date de reglement (YYYY-MM-DD) : ");
    obj.setDate(date);

    double montant = View::promptDouble("Donner le montant du reglement : ");
    obj.setMontant(montant);

    return obj;
}