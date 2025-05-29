#include <exception>

#include "CalendrierPaiementService.hpp"
#include "../repository/EtudiantRepository.hpp"
#include "../repository/ClasseRepository.hpp"
#include <exception>
#include <stdexcept>

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

CalendrierPaiementService &CalendrierPaiementService::instance()
{
    static CalendrierPaiementService inst;
    return inst;
}

bool CalendrierPaiementService::exist(const std::string& id){
    return CalendrierPaiementService::exist(id);
}
