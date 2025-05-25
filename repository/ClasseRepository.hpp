#pragma once

#include <string>
#include <vector>
#include <functional>
#include "Classe.hpp"

class ClasseRepository {
private:
    static std::string getFilePath(const std::string& id);

public:
    // Vérifier si l'objet existe
    static bool exists(const std::string& id);

    // Sauvegarde (insert ou update)
    static bool save(const Classe& obj);

    // Suppression
    static bool remove(const std::string& id);

    // Recherche par id (renvoie un objet par défaut si pas trouvé)
    static Classe findById(const std::string& id);

    // Sélectionne toutes les classes
    static std::vector<Classe> findAll();

    // Recherche avec un filtre prédicat
    static std::vector<Classe> findBy(std::function<bool(const Classe&)> predicate);
};
