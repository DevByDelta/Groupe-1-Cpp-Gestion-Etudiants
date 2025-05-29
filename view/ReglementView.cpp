#include <stdexcept>

#include "ReglementView.hpp"
#include "EtudiantRepository.hpp"
#include "ClasseRepository.hpp"
#include "View.hpp"

Reglement ReglementView::saisir(){
    Reglement r = Reglement();
    r.setEtudiantCode(saisirEtudiantCode()) ;
    r.setClasseId(saisirClasseId())  ;
    r.setMontant(saisirMontant());
    return r;
}

std::string ReglementView::saisirEtudiantCode() {
    while (true) {
        std::string code = View::promptString("Donner le code de l'étudiant pour ce règlement: ");
        if (EtudiantRepository::exists(code)) {
            return code;
        }
        View::error("Code invalide ! Cet étudiant n'existe pas.");
    }
}
std::string ReglementView::saisirClasseId() {
    while (true) {
        std::string cid = View::promptString("Donner l'ID de la classe associée: ");
        if (ClasseRepository::exists(cid)) {
            return cid;
        
        }
        View::error("ID invalide ! Cette classe n'existe pas.");
    }
}


double ReglementView::saisirMontant(){
    return View::promptDouble("donner le montant du reglement");
    
}
void ReglementView::displayAll(std::vector<Reglement> reglements){
    for (auto r : reglements)
    {
    View::showMessage(r.toString());
    }
}

