#include "../h/CaelisEngine.h"

using namespace Caelis::Core::Input;
using Caelis::Core::Log;

Keyboard::Keyboard()
    {
    mEvent = IEvent::getInstance();
    Log::getInstance()->write(2,"[Keyboard]-> Singleton Created.");
    }

Keyboard::~Keyboard()
    {
    Log::getInstance()->write(2,"[Keyboard]-> Singleton Destroyed.");
    }


bool Keyboard::getKey(SDLKey key, bool up, SDLMod mod)
    {

    if(up)
        {
        if(mEvent->get().key.state == SDL_RELEASED)
            {
            return (mEvent->get().key.keysym.sym==key) ? true : false;
            }
        }
    else
        {
        if(mKey[key] &&
            ((mod != KMOD_NONE)?(SDL_GetModState()&mod):mod == KMOD_NONE)
            && mEvent->get().key.state == SDL_PRESSED)
            {
            mLastKey = key;
            return true;
            }
        return false;
        }
    }

SDLKey Keyboard::getLastKey()
    {
    return mLastKey;
    }

void Keyboard::addFilter(SDLKey key, SDLMod mod, int(*func)(), bool active)
    {
    Filter filter;
    filter.key = key;
    filter.mod = mod;
    if( (filter.function = func)==NULL) return;
    filter.active = active;
    mFilters.push_back( filter );
    }

void Keyboard::deleteFilter(SDLKey key, SDLMod mod, int(*func)())
    {
    std::list<Filter>::iterator it;
    for(it = mFilters.begin(); it != mFilters.end(); it++)
        {
        if( (*it).key == key && (*it).mod == mod && (*it).function == func)
            {
            mFilters.erase(it);
            }
        }
    }

void Keyboard::step()
    {
    mKey = SDL_GetKeyState(NULL);
    mEvent->poll();
        std::list<Filter>::iterator it;
        for(it = mFilters.begin(); it != mFilters.end(); it++)
            {
            if( mKey[(*it).key]

                    && (((*it).mod != KMOD_NONE)?(SDL_GetModState()&(*it).mod):(*it).mod == KMOD_NONE)

                    && (*it).active == true)
                {
                if( (*it).function != NULL) (*it).function();
                else Log::getInstance()->write(2,"[Keyboard]-> Avoiding NULL function pointer from callback.");
                }
            }
    }
