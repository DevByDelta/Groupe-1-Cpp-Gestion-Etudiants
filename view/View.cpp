#include <iostream>
#include <limits>
#include <stdexcept>
#include <map>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <locale.h>


#include "View.hpp"

#include <windows.h>
#include <thread>
#include <chrono>

// ── Barre de chargement qui part pleine et se vide ───────────────
void View::countdownBar(int width, int total_ms)
{
    SetConsoleOutputCP(CP_UTF8);                     // blocs Unicode
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    static const WORD grad[] = {                     // vert → jaune → rouge
        FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        FOREGROUND_RED   | FOREGROUND_INTENSITY
    };

    const char FULL[]  = u8"#";
    const char EMPTY[] = u8".";
    int delay = total_ms / width;

    for (int filled = width; filled >= 0; --filled) {
        int idx = (filled > width*2/3) ? 0 : (filled > width/3 ? 1 : 2);
        SetConsoleTextAttribute(hOut, grad[idx]);

        std::cout << '\r'
                  << std::string(filled, *FULL)
                  << std::string(width - filled, *EMPTY)
                  << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    SetConsoleTextAttribute(hOut, 7);                // couleur par défaut
    std::cout << "\r\033[K✓ Terminé\n";
}


// ── Spinner "braille" coloré ────────────────────────────────────────────
void View::loader(int cycles, int delay_ms)
{
    // 1. UTF-8 pour les caractères braille
    SetConsoleOutputCP(CP_UTF8);

    // 2. Cache le curseur pour l'effet propre
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(hOut, &curInfo);
    CONSOLE_CURSOR_INFO curInfoHidden = curInfo;
    curInfoHidden.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &curInfoHidden);

    // 3. Tableaux de frames et de couleurs (rouge → jaune → vert)
    static const char* frame[]  = {u8"⣾",u8"⣽",u8"⣻",u8"⢿",
                                   u8"⡿",u8"⣟",u8"⣯",u8"⣷"};
    static const WORD  color[]  = {FOREGROUND_RED | FOREGROUND_INTENSITY,
                                   FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
                                   FOREGROUND_GREEN | FOREGROUND_INTENSITY};

    // 4. Boucle d'animation
    for (int i = 0; i < cycles; ++i) {
        // change progressivement la couleur
        SetConsoleTextAttribute(hOut, color[(i * 3) / cycles]);
        std::cout << '\r' << frame[i & 7] << " Chargement..." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }

    // 5. Nettoyage : couleur & curseur
    SetConsoleTextAttribute(hOut, 7);          // blanc par défaut
    SetConsoleCursorInfo(hOut, &curInfo);      // restaure la visibilité du curseur
    showMessage("\r✓ Terminé            \n");
}

void View::banner(const std::string& msg, char deco, int width) {
    int msgLen = msg.size();
    int decoLen = width - msgLen - 2; // 2 espaces autour du texte
    int left = decoLen / 2;
    int right = decoLen - left;

    // Si le message est trop long, adapte la largeur minimale
    if (decoLen < 0) {
        left = right = 1;
    }
    std::cout 
        << std::string(left, deco)
        << " " << msg << " "
        << std::string(right, deco)
        << std::endl;
}

void View::showMessage(const std::string &message)
{
    std::cout << message << std::endl;
}

void View::showStringObject(const std::string& obs){
    std::cout << "\033[35m" << obs << "\033[0m" << std::endl;
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
            error("Entrée invalide. Veuillez saisir un entier valide.");
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
            error("Entrée invalide. Veuillez saisir un nombre réel valide.");
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
        error("Réponse invalide. Veuillez répondre par 'o' (oui) ou 'n' (non).");
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
    const std::string& titre,
    const std::string& separateur,
    int largeur,
    const std::string& prefix
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
        std::cout << "\033[34m" << sepLine << "\033[0m" << std::endl;
        std::cout << std::setw(titrePos + titre.size()) << titre << std::endl;
        std::cout << "\033[34m" << sepLine << "\033[0m" << std::endl;
        int i = 1;
        for (const auto& pair : menu) {
            std::cout << std::setw(2) << "\033[33m" << i << ". " << "\033[34m" << prefix << "\033[1m\033[36m"  << pair.second << "\033[0m" << std::endl;
            ++i;
        }
        std::cout << std::setw(2) << "\033[33m" << i << ". " << "\033[34m" << prefix << "\033[1m\033[31m" << "Quitter/Retour" << "\033[0m" << std::endl;
            ++i;
        std::cout << "\033[34m" << sepLine << "\033[0m" << std::endl;
        int choix = promptInt("Votre choix: ");

        if(choix <= 0 || choix > taille + 1){
            error("Numéro d'option limité à [1," + std::to_string(taille + 1) + "]");
        }
        else if (choix == taille + 1 ){
            return "quit";
        }
        else{
            return cles[choix - 1];
        }
    }
}

