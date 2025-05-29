#include <exception>

#include "CalendrierPaiementService.hpp"
#include "EtudiantRepository.hpp"
#include "ClasseRepository.hpp"

CalendrierPaiementService::CalendrierPaiementService() {}


void CalendrierPaiementService::validerMetierEtudiantCode(CalendrierPaiement& cp, const std::string& etudiantCode){
    if(!EtudiantRepository::exists(etudiantCode)){
        throw std::runtime_error("Etudiant code invalide: " + etudiantCode);
    }
    cp.setEtudiantCode(etudiantCode);
}

void CalendrierPaiementService::validerMetierClasseId(CalendrierPaiement& cp, const std::string& classeId){
    if(!ClasseRepository::exists(classeId)){
        throw std::runtime_error("Classe ID invalide: " + classeId);
    }
    cp.setClasseId(classeId);
}

void CalendrierPaiementService::validerMetierEchancier(CalendrierPaiement& cp, const Echeancier::Type& echeancier){
    cp.setEcheancier(echeancier);
}