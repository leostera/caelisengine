#include "../h/CaelisEngine.h"

using namespace Caelis::Scene;
using Caelis::Core::Log;

ParticleManager::ParticleManager()
    {
    Log::getInstance()->write(2,"[ParticleManager]-> Singleton Created.");
    }

ParticleManager::~ParticleManager()
    {
    std::vector<CParticleSystem*>::iterator it;
    for(it = mSystems.begin(); it != mSystems.end(); it++)
        {
        delete (*it);
        (*it) = NULL;
        }
    mSystems.clear();
    Log::getInstance()->write(2,"[ParticleManager]-> Singleton Destroyed.");
    }

CParticleSystem* ParticleManager::getNewSystem()
    {
    CParticleSystem* tmp;
    mSystems.push_back(tmp);
    (*mSystems.end()) = new CParticleSystem();
    return (*mSystems.end());
    }

void ParticleManager::add(CParticleSystem* sys)
    {
    if(sys != NULL)
        mSystems.push_back(sys);
    }

void ParticleManager::del(CParticleSystem* sys)
    {
    std::vector<CParticleSystem*>::iterator it;
    for(it = mSystems.begin(); it != mSystems.end(); it++)
        {
        if( (*it) == sys)
            {
            delete (*it);
            (*it) = NULL;
            return;
            }
        }
    }

void ParticleManager::step()
    {
    std::vector<CParticleSystem*>::iterator it;
    for(it = mSystems.begin(); it != mSystems.end(); it++)
        {
        if( (*it)->isVisible())
            {
            (*it)->step();
            }
        }
    }
