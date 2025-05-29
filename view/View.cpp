#include <iostream>
#include <limits>
#include <stdexcept>
#include <map>
#include <iomanip>
#include <vector>

#include "View.hpp"

View::~View(){}

void View::showMessage(const std::string &message)
{
    std::cout << message << std::endl;
}

std::string View::promptString(const std::string &message)
{
    std::string input;
    std::cout << message;
    std::getline(std::cin, input);
    return input;
}

int View::promptInt(const std::string &message)
{
    int value;
    std::string input;
    while (true)
    {
        input = promptString(message);
        try
        {
            size_t pos;
            value = std::stoi(input, &pos);
            if (pos != input.length())
            {
                throw std::invalid_argument("Extra characters after number");
            }
            break;
        }
        catch (const std::exception &)
        {
            showMessage("Entrée invalide. Veuillez saisir un entier valide.");
        }
    }
    return value;
}

double View::promptDouble(const std::string &message)
{
    double value;
    std::string input;
    while (true)
    {
        input = promptString(message);
        try
        {
            size_t pos;
            value = std::stod(input, &pos);
            if (pos != input.length())
            {
                throw std::invalid_argument("Extra characters after number");
            }
            break;
        }
        catch (const std::exception &)
        {
            showMessage("Entrée invalide. Veuillez saisir un nombre réel valide.");
        }
    }
    return value;
}

bool View::promptYesNo(const std::string &message)
{
    std::string input;
    while (true)
    {
        showMessage(message + " (o/n) : ");
        std::getline(std::cin, input);
        if (input == "o" || input == "O" || input == "oui" || input == "Oui")
            return true;
        if (input == "n" || input == "N" || input == "non" || input == "Non")
            return false;
        showMessage("Réponse invalide. Veuillez répondre par 'o' (oui) ou 'n' (non).");
    }
}

void View::warning(const std::string &msg)
{
    std::cout << "\033[33m" << msg << "\033[0m" << std::endl; // Jaune
}
void View::success(const std::string &msg)
{
    std::cout << "\033[32m" << msg << "\033[0m" << std::endl; // Vert
}
void View::error(const std::string &msg)
{
    std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

std::string View::afficherMenu(
    const std::map<std::string, std::string>& menu,
    const std::string& titre = "FONCTIONNALITÉS DISPONIBLES",
    const std::string& separateur = "=",
    int largeur = 40,
    const std::string& prefix = "→ "
) {
    std::string sepLine(largeur, separateur.empty() ? '=' : separateur[0]);
    int titrePos = (largeur - titre.size()) / 2;
    int taille = menu.size();

    // 1. Stocker les clés dans un vecteur, dans l'ordre d'affichage
    std::vector<std::string> cles;
    for (const auto& pair : menu) {
        cles.push_back(pair.first);
    }

    while (true)
    {
        std::cout << sepLine << std::endl;
        std::cout << std::setw(titrePos + titre.size()) << titre << std::endl;
        std::cout << sepLine << std::endl;
        int i = 1;
        for (const auto& pair : menu) {
            std::cout << std::setw(2) << i << ". " << prefix << pair.second << std::endl;
            ++i;
        }
        std::cout << sepLine << std::endl;
        int choix = promptInt("Votre choix: ");

        if(choix <= 0 || choix > taille){
            error("Numéro d'option limité à [1," + std::to_string(taille) + "]");
        }
        else{
            return cles[choix - 1];
        }
    }
}

