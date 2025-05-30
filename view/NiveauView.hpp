#pragma once
#include "../model/enum/Niveau.hpp"
#include "View.hpp"
class NiveauView : public View
{
public:
    static Niveau::Type choisir();
};
