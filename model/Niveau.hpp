#pragma once
#include <string>

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
    std::string toString(Type e);
    Type fromString(const std::string &str);
}
