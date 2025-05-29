#pragma once
#include "../model/enum/Echeancier.hpp"
#include "View.hpp"

class EcheancierView : public View
{
private:
    EcheancierView() {}
    EcheancierView(const EcheancierView &) = delete;
    EcheancierView &operator=(const EcheancierView &) = delete;

public:
    static EcheancierView &instance();
    Echeancier::Type choisir();
};
