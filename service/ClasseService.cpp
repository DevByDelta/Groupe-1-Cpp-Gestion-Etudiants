#include <exception>

#include "ClasseService.hpp"
#include "../repository/FormationRepository.hpp"
#include "../repository/ClasseRepository.hpp"
#include "../repository/EtudiantRepository.hpp"
#include <exception>
#include <stdexcept>

void ClasseService::validerMetierNom(Classe &classe, const std::string &nom)
{
    classe.setNom(nom);
}

void ClasseService::validerMetierFormationId(Classe &classe, const std::string &formationId)
{
    if (!FormationRepository::exists(formationId))
    {
        throw std::runtime_error("Formation ID invalide :" + formationId);
    }
    classe.setNom(formationId);
}

bool ClasseService::enregistrerClasse(Classe &classe)
{
    return ClasseRepository::save(classe);
}
bool ClasseService::supprimerClasse(const std::string &id)
{
    return ClasseRepository::remove(id);
}
Classe ClasseService::rechercherClasse(const std::string &id)
{
    return ClasseRepository::findById(id);
}
std::vector<Classe> ClasseService::avoirTousClasses()
{
    return ClasseRepository::findAll();
}
double ClasseService::avoirCoutFormation(const std::string &id)
{
    Classe cl = ClasseRepository::findById(id);
    std::string formationId = cl.getFormationId();
    Formation f = FormationRepository::findById(formationId);
    return f.getCoutAnnuel();
}

bool ClasseService::exist(const std::string &id)
{
    return ClasseRepository::exists(id);
}

int ClasseService::avoirEffectif(const std::string &id)
{
    auto ets = EtudiantRepository::findBy([&](const Etudiant &e)
                                          { return e.getClasseId() == id; });
    return ets.size();
}