#pragma once

#include "View.hpp"
#include "Classe.hpp"

class ClasseView {
public:
    static Classe saisir();
    static void ajouterEtudiantCode(Classe cl);
    ClasseView();
};
