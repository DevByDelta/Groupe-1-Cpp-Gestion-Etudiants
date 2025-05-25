#pragma once

// Dossiers de stockage principaux
#define DATABASE_PATH        "database/"
#define CLASSES_PATH         DATABASE_PATH "classes/"
#define ETUDIANTS_PATH       DATABASE_PATH "etudiants/"
#define REGLEMENTS_PATH      DATABASE_PATH "reglements/"
#define FORMATIONS_PATH      DATABASE_PATH "formations/"
#define CALENDRIERS_PATH     DATABASE_PATH "calendriers/"
#define EXTENSION_DB         ".txt"
#define M 100

// Macros pour les chemins complets d'un fichier objet
#define CLASS_FILE(id)       (CLASSES_PATH + std::string(id) + EXTENSION_DB)
#define ETUDIANT_FILE(id)    (ETUDIANTS_PATH + std::string(id) + EXTENSION_DB)
#define REGLEMENT_FILE(id)   (REGLEMENTS_PATH + std::string(id) + EXTENSION_DB)
#define FORMATION_FILE(id)   (FORMATIONS_PATH + std::string(id) + EXTENSION_DB)
#define CALENDRIER_FILE(id)  (CALENDRIERS_PATH + std::string(id) + EXTENSION_DB)
