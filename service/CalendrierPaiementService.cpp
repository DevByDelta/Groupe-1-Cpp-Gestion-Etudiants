#include <exception>

#include "CalendrierPaiementService.hpp"
#include "../repository/EtudiantRepository.hpp"
#include "../repository/ClasseRepository.hpp"
#include "../repository/CalendrierPaiementRepository.hpp"
#include <exception>
#include <stdexcept>



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

bool CalendrierPaiementService::enregistrer(CalendrierPaiement& cp){
    return CalendrierPaiementRepository::save(cp);
}

bool CalendrierPaiementService::exist(const std::string& id){
    return CalendrierPaiementService::exist(id);
}
