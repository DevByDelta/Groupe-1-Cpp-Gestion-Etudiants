#include "Echeancier.hpp"

namespace Echeancier
{

    std::string toString(Type e)
    {
        switch (e)
        {
        case Type::EnUneFois:
            return "En une fois";
        case Type::Semestriel:
            return "Semestriel";
        case Type::Trimestriel:
            return "Trimestriel";
        case Type::Mensuel:
            return "Mensuel";
        default:
            return "Invalide";
        }
    }

    Type fromString(const std::string &str)
    {
        if (str == "En une fois")
            return Type::EnUneFois;
        if (str == "Semestriel")
            return Type::Semestriel;
        if (str == "Trimestriel")
            return Type::Trimestriel;
        if (str == "Mensuel")
            return Type::Mensuel;
        return Type::Invalide;
    }

}
