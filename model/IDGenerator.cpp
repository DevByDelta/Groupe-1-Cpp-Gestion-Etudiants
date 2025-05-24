#include "IDGenerator.hpp"
// Aminata
#include <typeinfo>
#include <sstream>
std::unordered_map<std::string, int> IDGenerator::counters;
template<typename T>
std::string IDGenerator::generate() {
    std::string typeName = typeid(T).name();
    int& counter = counters[typeName];
    counter++;
    
    std::ostringstream oss;
    oss << typeName << "_" << counter;
    return oss.str();
}
#include "Etudiant.hpp"
#include "Formation.hpp"
#include "Classe.hpp"
#include "Niveau.hpp"

template std::string IDGenerator::generate<Etudiant>();
template std::string IDGenerator::generate<Formation>();
template std::string IDGenerator::generate<Classe>();
template std::string IDGenerator::generate<Niveau>();


