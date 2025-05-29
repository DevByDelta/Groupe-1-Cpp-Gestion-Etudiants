#include <iostream>
#include <map>
#include <string>

#include "view/ClasseView.hpp"
#include "view/CalendrierPaiementView.hpp"
#include "view/EtudiantView.hpp"
#include "view/ReglementView.hpp"
#include "view/FormationView.hpp"

using namespace std;

static std::map<std::string, std::string> MENU_PRINCIPAL= {
    {"etudiants", "Gestion des étudiants"},
    {"classes", "Gestion des classes"},
    {"formations", "Gestion des formations"},
    {"paiements", "Gestion des paiements"},
    {"quitter", "Quitter"}
};

class Main {
public:
    Main(){}
    void run() {
        while(true){
            std::string key = ClasseView::instance().afficherMenu(MENU_PRINCIPAL, "Menu principal", "+", 40, "<<");

            if (key == "quitter"){
                return;
            }
        };

    }
};

int main() {
    Main app;
    app.run();
    return 0;
}
