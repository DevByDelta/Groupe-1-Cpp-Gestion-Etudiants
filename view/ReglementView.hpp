#pragma once

#include <string>
#include <vector>

#include "Reglement.hpp"

class ReglementView {
public:
    static Reglement input();
    static  std::string saisirEtudiantCode();
    static  std::string saisirClasseId();
    static double saisirMontant();
    void displayAll(std::vector<Reglement> reglements);

};
