#include "Classe.hpp"

// Kiné

Classe::Classe() {}
const std::string& Classe::getId()const {
        return this -> id;
    }
const std::string& Classe::getNom()const {
        return this -> nom;
    }
void Classe::setNom(const std::string &nom){
        this -> nom = nom;
    }
int Classe::getIdFormation()const{
    return this -> idFormation;
}
const std::vector<std::string> Classe:: getEtudiantCodes()const{
    return this -> etudiantCodes;
}
std::string Classe::toString() const {
    return "Classe[ ID:" + id + 
    ", Nom:" + nom + 
    ", ID Formation:" + std::to_string(idFormation) +"]";
}
Classe::~Classe() {}
