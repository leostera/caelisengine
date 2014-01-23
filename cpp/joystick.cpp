#include "../h/CaelisEngine.h"

using namespace Caelis::Core::Input;

Joystick::Joystick()
    {
    Log::getInstance()->write(2,"[Joystick]-> Singleton Created.");
    }

Joystick::~Joystick()
    {
    std::vector<Stick*>::iterator it;
    for(it = mSticks.begin(); it != mSticks.end(); it++)
        {
        if( (*it) )
            {
            SDL_JoystickClose( (*it)->stick );
            delete (*it);
            (*it) = NULL;
            }
        }
    mSticks.clear();

    Log::getInstance()->write(2,"[Joystick]-> Singleton Destroyed.");
    }


bool Joystick::step()
    {
    /*
    if(mNumJoysticks != SDL_NumJoysticks())
        mNumJoysticks = SDL_NumJoysticks();
    */
    return true;
    }

Stick* Joystick::open(Uint32 number)
    {
    Stick* tmp = new Stick;
    tmp->stick = SDL_JoystickOpen(number);
    if(tmp == NULL) return NULL;

    mSticks.push_back(tmp);
    return (*mSticks.end());
    }

void Joystick::close(Stick* joy)
    {
    std::vector<Stick*>::iterator it;
    for(it = mSticks.begin(); it != mSticks.end(); it++)
        {
        if( (*it) )
            {
            SDL_JoystickClose( (*it)->stick );
            delete (*it);
            (*it) = NULL;
            }
        }
    }
