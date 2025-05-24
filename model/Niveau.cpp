#include "Niveau.hpp"
#include<stdexcept>
inline std::string niveauToString(Niveau niveau) {
    switch (niveau) {
        case Niveau::L1: return "L1";
        case Niveau::L2: return "L2";
        case Niveau::L3: return "L3";
        case Niveau::M1: return "M1";
        case Niveau::M2: return "M2";
        case Niveau::D1: return "D1";
        case Niveau::D2: return "D2";
        default: return "Inconnu";
    }
}

inline Niveau stringToNiveau(const std::string& str) {
    if (str == "L1") return Niveau::L1;
    if (str == "L2") return Niveau::L2;
    if (str == "L3") return Niveau::L3;
    if (str == "M1") return Niveau::M1;
    if (str == "M2") return Niveau::M2;
    if (str == "D1") return Niveau::D1;
    if (str == "D2") return Niveau::D2;
    throw std::invalid_argument("Niveau invalide : " + str);
}
