#pragma once
#include <string>
#include <array>

namespace Niveau
{
    enum class Type
    {
        L1,
        L2,
        L3,
        M1,
        M2,
        D1,
        D2,
        Invalide
    };

    inline const std::array<Type, 7>& allTypes() {
        static const std::array<Type, 7> arr = { Type::L1, Type::L2, Type::L3, Type::M1, Type::M2, Type::D1, Type::D2 };
        return arr;
    }
    std::string toString(Type e);
    Type fromString(const std::string &str);
    
}
