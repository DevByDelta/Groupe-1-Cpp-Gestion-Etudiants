#pragma once

#include <vector>
#include <string>


#include "Formation.hpp"

class FormationView {
public:
    static Formation input();
    static std::string saisirFiliere();
    static Niveau::Type saisirNiveau();
    static int saisirDureeAnnuelle();
    static double saisirCoutAnnuel();
    void displayAll(std::vector<Formation> formations);
};
