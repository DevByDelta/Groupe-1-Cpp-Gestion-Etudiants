#include "FormationView.hpp"
#include "IDGenerator.hpp"
#include "Niveau.hpp"

FormationView::FormationView() {}
FormationView::~FormationView() {}

Formation FormationView::saisir() {
    Formation obj;
    // Génération automatique de l'ID
    obj.setId(IDGenerator::generate("FR"));

    // Saisie des champs
    std::string filiere = View::promptString("Donner la filiere : ");
    obj.setFiliere(filiere);

    std::string annee = View::promptString("Donner l'annee academique (ex: 2024/2025) : ");
    obj.setAnneeAcademique(annee);

    std::string niveauStr = View::promptString("Donner le niveau (L1, L2, L3, M1, M2, D1, D2) : ");
    obj.setNiveau(Niveau::fromString(niveauStr));

    int duree = View::promptInt("Donner la duree annuelle : ");
    obj.setDureeAnnuelle(duree);

    double cout = View::promptDouble("Donner le cout annuel : ");
    obj.setCoutAnnuel(cout);

    return obj;
}
