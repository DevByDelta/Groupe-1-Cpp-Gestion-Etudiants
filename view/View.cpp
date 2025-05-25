#include "View.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

void View::showMessage(const std::string& message) {
    std::cout << message << std::endl;
}

std::string View::promptString(const std::string& message) {
    std::string input;
    showMessage(message);
    std::getline(std::cin, input);
    return input;
}

int View::promptInt(const std::string& message) {
    int value;
    std::string input;
    while (true) {
        input = promptString(message);
        try {
            size_t pos;
            value = std::stoi(input, &pos);
            if (pos != input.length()) {
                throw std::invalid_argument("Extra characters after number");
            }
            break;
        } catch (const std::exception&) {
            showMessage("Entrée invalide. Veuillez saisir un entier valide.");
        }
    }
    return value;
}

double View::promptDouble(const std::string& message) {
    double value;
    std::string input;
    while (true) {
        input = promptString(message);
        try {
            size_t pos;
            value = std::stod(input, &pos);
            if (pos != input.length()) {
                throw std::invalid_argument("Extra characters after number");
            }
            break;
        } catch (const std::exception&) {
            showMessage("Entrée invalide. Veuillez saisir un nombre réel valide.");
        }
    }
    return value;
}

bool View::promptYesNo(const std::string& message) {
    std::string input;
    while (true) {
        showMessage(message + " (o/n) : ");
        std::getline(std::cin, input);
        if (input == "o" || input == "O" || input == "oui" || input == "Oui")
            return true;
        if (input == "n" || input == "N" || input == "non" || input == "Non")
            return false;
        showMessage("Réponse invalide. Veuillez répondre par 'o' (oui) ou 'n' (non).");
    }
}
