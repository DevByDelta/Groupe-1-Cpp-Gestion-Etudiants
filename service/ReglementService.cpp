#include "ReglementService.hpp"
#include "EtudiantRepository.hpp"
#include "ClasseRepository.hpp"
#include  "Reglement.hpp"
#include <stdexcept>
ReglementService::ReglementService() {}
void ReglementService::validerMetierEtudiantCode(Reglement& r, const std::string& code) {
    if (!EtudiantRepository::exists(code)) {
        throw std::runtime_error("Code étudiant invalide : " + code);
    }
    r.setEtudiantCode(code);
}
void ReglementService::validerMetierClasseId(Reglement& r, const std::string& classeId) {
    if (!ClasseRepository::exists(classeId)) {
        throw std::runtime_error("Classe ID invalide : " + classeId);
    }
    r.setClasseId(classeId);
}
void ReglementService::validerMetierMontant(Reglement& r,double montant){
    r.setMontant(montant);
}