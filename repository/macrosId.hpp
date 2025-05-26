#pragma once

#include "pathsConst.hpp"

// Macros pour les chemins complets d'un fichier objet
#define CLASS_FILE(id)       (CLASSES_PATH + std::string(id) + EXTENSION_DB)
#define ETUDIANT_FILE(id)    (ETUDIANTS_PATH + std::string(id) + EXTENSION_DB)
#define REGLEMENT_FILE(id)   (REGLEMENTS_PATH + std::string(id) + EXTENSION_DB)
#define FORMATION_FILE(id)   (FORMATIONS_PATH + std::string(id) + EXTENSION_DB)
#define CALENDRIER_FILE(id)  (CALENDRIERS_PATH + std::string(id) + EXTENSION_DB)
