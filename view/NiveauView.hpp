#pragma once
#include "Niveau.hpp"
#include "View.hpp"
class NiveauView : public View
{
private:
    NiveauView() {}
    NiveauView(const NiveauView &) = delete;
    NiveauView &operator=(const NiveauView &) = delete;

public:
    static NiveauView &instance();
    Niveau::Type choisir();
};
