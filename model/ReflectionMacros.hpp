#pragma once
#include <string>
#include <map>
#include <sstream>
#include <vector>

// Utilitaire
inline std::vector<std::string> splitList(const std::string& csv, char delim = ',') {
    std::vector<std::string> out;
    std::istringstream iss(csv);
    std::string item;
    while (std::getline(iss, item, delim)) {
        out.push_back(item);
    }
    return out;
}

// Macros pour les set rapide dans les méthodes To
#define SET_STRING(map, obj, attr) \
    if ((map).find(#attr) != (map).end()) \
        (obj).set##attr((map).at(#attr));

#define SET_BOOL(map, obj, attr) \
    if ((map).find(#attr) != (map).end()) \
        (obj).set##attr((map).at(#attr) == "1");

#define SET_INT(map, obj, attr) \
    if ((map).find(#attr) != (map).end()) \
        (obj).set##attr(std::stoi((map).at(#attr)));

#define SET_DOUBLE(map, obj, attr) \
    if ((map).find(#attr) != (map).end()) \
        (obj).set##attr(std::stod((map).at(#attr)));

#define SET_LIST(map, obj, attr, addMethod) \
    if ((map).find(#attr) != (map).end()) { \
        auto list = splitList((map).at(#attr)); \
        for (const auto& item : list) { \
            (obj).addMethod(item); \
        } \
    }

#define SET_DATE(map, obj, attr) \
    if ((map).find(#attr) != (map).end()) \
        (obj).set##attr(Date::fromString((map).at(#attr)));

#define SET_LIST_DATE(map, obj, attr, addMethod)              \
  if ((map).find(#attr) != (map).end()) {                     \
    auto _lst = splitList((map).at(#attr));                  \
    for (const auto& _s : _lst)                              \
      (obj).addMethod( Date::fromString(_s) );               \
  }


// Pour tous les enums avec Namespace::fromString
#define SET_ENUM(map, obj, attr, Namespace) \
    if ((map).find(#attr) != (map).end()) { \
        (obj).set##attr(Namespace::fromString((map).at(#attr))); \
    }


// // méthode rapide pour des messages personnalisés d'exception
// inline std::string makeInvalidMsg(const std::string& type, int id) {
//     return type + " id/code invalide : " + std::to_string(id);
// }