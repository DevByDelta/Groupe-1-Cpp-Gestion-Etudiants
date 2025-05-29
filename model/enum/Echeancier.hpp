#pragma once
#include <string>
#include <array>

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

    inline const std::array<Type, 4>& allTypes() {
        static const std::array<Type, 4> arr = {
            Type::EnUneFois, Type::Semestriel, Type::Trimestriel, Type::Mensuel
        };
        return arr;
    }

    std::string toString(Type e);

    Type fromString(const std::string &str);

}
