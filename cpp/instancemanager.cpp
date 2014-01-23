#include "../h/CaelisEngine.h"

using namespace Caelis::Instance;
using Caelis::Core::Log;

InstanceManager::InstanceManager()
    {
    Log::getInstance()->write(2,"[InstanceManager]-> Singleton Created.");
    mInstanceNumber = 0;
    }

InstanceManager::~InstanceManager()
    {
    deleteAll();
    Log::getInstance()->write(2,"[InstanceManager]-> Singleton Destroyed.");
    }

IInstance* InstanceManager::get(Uint32 instanceID)
    {
    std::list<IInstance*>::iterator i;
    for(i = mInstances.begin(); i != mInstances.end(); i++)
        {
        if((*i)->getID()==instanceID) return (*i);
        }
    return NULL;
    }

void InstanceManager::add(IInstance *instance)
    {
    if(instance == NULL)
        {
        Log::getInstance()->write(2,"[InstanceManager]-> trying to add a NULL pointer.");
        return;
        }
    mInstanceNumber++;
    mInstances.push_back(instance);
    instance->create();
    Log::getInstance()->write(2,"[InstanceManager]-> added an Instance with the following ID: %d .\n\t\t     Instance Number: %d",true,instance->getID(),mInstanceNumber);
    }

void InstanceManager::drop(IInstance *instance)
    {
    if(instance == NULL)
        {
        Log::getInstance()->write(2,"[InstanceManager]-> trying to delete a NULL pointer.");
        return;
        }
    if(mInstances.empty())
        {
        Log::getInstance()->write(2,"[InstanceManager]-> no instances to delete.");
        return;
        }
    std::list<IInstance*>::iterator i;
    for (i = mInstances.begin(); i != mInstances.end(); i++)
        {
        if ((*i) == instance)
            {
            Uint32 id=instance->getID();
            instance->destroy();
            mInstances.erase(i);
            (*i) = NULL;
            instance = NULL;
            mInstanceNumber--;
            if(mInstanceNumber<0)
                {
                Log::getInstance()->write(2,"[InstanceManager]-> trying to delete more instances than added. Breaking Loop.");
                break;
                }
            Log::getInstance()->write(2,"[InstanceManager]-> deleted an Instance with the following ID: %d.",true,id);
            break;
            }
        }
    }

void InstanceManager::deleteAll()
    {
    if(mInstanceNumber < 1 && mInstances.empty())
        {
        Log::getInstance()->write(2,"[InstanceManager]-> no instances to delete.");
        return;
        }
    std::list<IInstance*>::iterator i;
    for(i=mInstances.begin(); i!=mInstances.end(); i++)
        {
		if (!(*i))
            {
			Log::getInstance()->write(2,"[InstanceManager]-> trying to delete a NULL pointer.");
			continue ;
            }
		(*i)->destroy();
		Log::getInstance()->write(2,"[InstanceManager]-> deleted an Instance with the following ID: %d.",true,(*i)->getID());
        (*i) = NULL ;
        }
    mInstances.remove(NULL) ;
    Log::getInstance()->write(2,"[InstanceManager]-> deleted all %d objects.",true,mInstanceNumber);
    mInstanceNumber = 0;
    }

void InstanceManager::step()
    {
    std::list<IInstance*>::iterator i;
    for(i = mInstances.begin(); i != mInstances.end(); i++)
        {
        if( (*i) == NULL)
            {
            Log::getInstance()->write(2,"[InstanceManager]-> NULL pointer avoided.");
            continue;
            }
        (*i)->step();
        if( (*i)->getVisible() ) (*i)->draw();
        }
    }
