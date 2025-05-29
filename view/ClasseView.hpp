#pragma once

#include <string>
#include <vector>

#include "View.hpp"
#include "Classe.hpp"

class ClasseView
{
public:
    static Classe saisir();
    static std::string saisirFormationId();
    static void ajouterEtudiantCode(Classe& cl);
    static void displayAll(const std::vector<Classe>& classes);
};
