#include "FormationView.hpp"
#include "View.hpp"
#include "NiveauView.hpp"

Formation FormationView::saisir()
{
    Formation f =Formation();
    f.setFiliere(       saisirFiliere()      );
    f.setNiveau(        saisirNiveau()       );
    f.setDureeAnnuelle( saisirDureeAnnuelle() );
    f.setCoutAnnuel(    saisirCoutAnnuel()   );

    return f;


}
std::string FormationView::saisirFiliere(){
    std::string fil=View::promptString("donner la filere");
        return fil;
}
Niveau::Type FormationView::saisirNiveau() {
    Niveau::Type niveau = NiveauView::choisir();
    return niveau;
}
int FormationView::saisirDureeAnnuelle() {
    int duree = View::promptInt("Donner la durée annuelle (en heures)");
    return duree;
}
double FormationView::saisirCoutAnnuel() {
    double coutAnnuel = View::promptDouble("Donner le coût annuel");
    return coutAnnuel;
}
void FormationView::displayAll(std::vector<Formation> formations)
{
    for (auto f : formations)
    {
    View::showMessage(f.toString());
    }
}