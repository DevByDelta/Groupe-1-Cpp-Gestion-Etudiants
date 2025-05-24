#include "Niveau.hpp"
namespace Niveau
{
    std::string toString(Type e)
    {
        switch (e)
        {
        case Type::L1:
            return "L1";
        case Type::L2:
            return "L2";
        case Type::L3:
            return "L3";
        case Type::M1:
            return "M1";
        case Type::M2:
            return "M2";
        case Type::D1:
            return "D1";
        case Type::D2:
            return "D2";
        default:
            return "Invalide";
        }
    }
    Type fromString(const std::string &str)
    {
        if (str == "L1")
            return Type::L1;
        if (str == "L2")
            return Type::L2;
        if (str == "L3")
            return Type::L3;
        if (str == "M1")
            return Type::M1;
        if (str == "M2")
            return Type::M2;
        if (str == "D1")
            return Type::D1;
        if (str == "D2")
            return Type::D2;
        return Type::Invalide;
    }
}
