#pragma once
#include <string>
#include <stdexcept>

enum class Niveau {
    L1, L2, L3,
    M1, M2,
    D1, D2
};
std::string  niveauToString(Niveau niveau);
Niveau stringToNiveau(const std::string& str);

