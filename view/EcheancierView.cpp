#include "EcheancierView.hpp"
#include <sstream>

Echeancier::Type EcheancierView::choisir()
{
    const auto &types = Echeancier::allTypes();
    int nbTypes = types.size();

    std::ostringstream oss;
    oss << "Veuillez choisir le type d'échéancier :\n";
    for (int i = 0; i < nbTypes; ++i)
    {
        oss << "  " << (i + 1) << "- " << Echeancier::toString(types[i]) << "\n";
    }
    oss << "Votre choix (1-" << nbTypes << ") : ";

    int choix = 0;
    while (true)
    {
        choix = promptInt(oss.str());
        if (choix >= 1 && choix <= nbTypes)
        {
            return types[choix - 1];
        }
        showMessage("Choix invalide. Veuillez recommencer.");
    }
}

EcheancierView &EcheancierView::instance()
{
    static EcheancierView inst;
    return inst;
}