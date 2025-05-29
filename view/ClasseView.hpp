#pragma once

#include <string>
#include <vector>

#include "View.hpp"
#include "Classe.hpp"

class ClasseView : public View
{
public:
    Classe input();
    void displayAll(const std::vector<Classe> &classes);

    std::string saisirFormationId();
    void ajouterEtudiantCode(Classe &cl);
};
