#include "../h/CaelisEngine.h"

using namespace Caelis::Core::Input;

IEvent::IEvent()
    {

    }

IEvent::~IEvent()
    {

    }

SDL_Event IEvent::get()
    {
    return mEvent;
    }

void IEvent::push(SDL_Event event)
    {
    if(SDL_PushEvent(&event)!=0)
        {
        if(event.type&SDL_ACTIVEEVENT
            || event.type&SDL_KEYDOWN
            || event.type&SDL_KEYUP
            || event.type&SDL_MOUSEMOTION
            || event.type&SDL_MOUSEBUTTONDOWN
            || event.type&SDL_MOUSEBUTTONUP
            || event.type&SDL_JOYAXISMOTION
            || event.type&SDL_JOYBALLMOTION
            || event.type&SDL_JOYHATMOTION
            || event.type&SDL_JOYBUTTONDOWN
            || event.type&SDL_JOYBUTTONUP
            || event.type&SDL_QUIT
            || event.type&SDL_SYSWMEVENT
            || event.type&SDL_VIDEORESIZE
            || event.type&SDL_USEREVENT) return;
        else
            return;
        }
    }

void IEvent::push()
    {
    SDL_PushEvent(&mEvent);
    }

bool IEvent::poll()
    {
    return (SDL_PollEvent(&mEvent)) ? true : false;
    }

void IEvent::pump()
    {
    if(!mPumped)
        {
        SDL_PumpEvents();
        mPumped = true;
        }
    }
