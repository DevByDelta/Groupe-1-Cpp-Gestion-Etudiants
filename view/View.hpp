#pragma once

#include <string>
#include <map>

class View
{
public:
    static void banner(const std::string &msg, char deco = '=', int width = 40);
    static void loader(int cycles = 50, int delay_ms = 22);
    static void countdownBar(int width = 30, int total_ms = 2000);
    static void showMessage(const std::string &message);
    static void showStringObject(const std::string &obs);
    static std::string promptString(const std::string &message);
    static int promptInt(const std::string &message);
    static double promptDouble(const std::string &message);
    static bool promptYesNo(const std::string &message);
    static void warning(const std::string &msg);
    static void success(const std::string &msg);
    static void error(const std::string &msg);
    static std::string afficherMenu(
        const std::map<std::string, std::string> &menu,
        const std::string &titre = "FONCTIONNALITÉS DISPONIBLES",
        const std::string &separateur = "=",
        int largeur = 40,
        const std::string &prefix = "→ ");
};
