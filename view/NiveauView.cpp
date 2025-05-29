#include "NiveauView.hpp"
#include "View.hpp"
#include <sstream>

Niveau::Type NiveauView::choisir() {
    const auto& types = Niveau::allTypes();
    int nbTypes = types.size();

    std::ostringstream oss;
    oss << "Veuillez choisir le niveau :\n";
    for (int i = 0; i < nbTypes; ++i) {
        oss << "  " << (i + 1) << "- " << Niveau::toString(types[i]) << "\n";
    }
    oss << "Votre choix (1-" << nbTypes << ") : ";

    int choix = 0;
    while (true) {
        choix = View::promptInt(oss.str());
        if (choix >= 1 && choix <= nbTypes) {
            return types[choix - 1];
        }
        View::showMessage("Choix invalide. Veuillez recommencer.");
    }
}
