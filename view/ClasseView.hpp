#pragma once

#include "View.hpp"
#include "Classe.hpp"

#include <string>

class ClasseView
{
public:
    static Classe saisir();
    static void ajouterEtudiantCode(Classe cl);
};
