#pragma once
#include <string>

namespace Echeancier
{

    enum class Type
    {
        EnUneFois,
        Semestriel,
        Trimestriel,
        Mensuel,
        Invalide
    };

    std::string toString(Type e);

    Type fromString(const std::string &str);

}
