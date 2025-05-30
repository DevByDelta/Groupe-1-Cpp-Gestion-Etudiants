#pragma once
#include "../model/enum/Echeancier.hpp"
#include "View.hpp"

class EcheancierView : public View
{
public:
    
    static Echeancier::Type choisir();
};
