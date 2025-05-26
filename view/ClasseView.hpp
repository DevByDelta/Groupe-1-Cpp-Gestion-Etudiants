#pragma once

#include "View.hpp"
#include "Classe.hpp"

class ClasseView
{
private:
    ClasseView();

public:
    static Classe saisir();
    static void ajouterEtudiantCode(Classe cl);
};
