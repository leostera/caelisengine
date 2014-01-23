#include "../h/CaelisEngine.h"

using namespace Caelis::Core::Input;
using Caelis::Core::Log;

Mouse::Mouse()
    {
    mEvent = IEvent::getInstance();
    mX = mY = mLastX = mLastY = 0;
    warp(0,0);

    for(int i=0; i<3; i++)
        {
        mButtons[i].x = -1;
        mButtons[i].y = -1;
        mButtons[i].state = 0;
        }
    mButtons[0].button = SDL_BUTTON_LEFT;
    mButtons[1].button = SDL_BUTTON_RIGHT;
    mButtons[2].button = SDL_BUTTON_MIDDLE;

    mLastButton.button = -1;
    mLastButton.x = -1;
    mLastButton.y = -1;
    mLastButton.state = 0;

    Log::getInstance()->write(2,"[Mouse]-> Singleton Created.");
    }

Mouse::~Mouse()
    {
    Log::getInstance()->write(2,"[Mouse]-> Singleton Destroyed.");
    }

Uint32 Mouse::step()
    {
    while(mEvent->poll())
        {
        if(mEvent->get().type==SDL_MOUSEMOTION)
            {
            mLastX = mX;
            mLastY = mY;
            mX = mEvent->get().button.x;
            mY = mEvent->get().button.y;
            mState = mEvent->get().motion.state;
            return 1;
            }
        else if(mEvent->get().type==SDL_MOUSEBUTTONDOWN)
            {
            mLastX = mX;
            mLastY = mY;
            mX = mEvent->get().button.x;
            mY = mEvent->get().button.y;
            short key=-1;
            switch(mEvent->get().button.button)
                {
                case SDL_BUTTON_LEFT:
                    key = 0;
                break;

                case SDL_BUTTON_RIGHT:
                    key = 1;
                break;

                case SDL_BUTTON_MIDDLE:
                    key = 2;
                break;
                }
            if(key > -1)
                {
                if(mButtons[key].state == SDL_PRESSED) return 1;
                mButtons[key].state = SDL_PRESSED;
                mButtons[key].x = mEvent->get().button.x;
                mButtons[key].y = mEvent->get().button.y;
                }
            return 1;
            }
        else if(mEvent->get().type==SDL_MOUSEBUTTONUP)
            {
            mLastX = mX;
            mLastY = mY;
            mX = mEvent->get().button.x;
            mY = mEvent->get().button.y;
            short key=-1;
            switch(mEvent->get().button.button)
                {
                case SDL_BUTTON_LEFT:
                    key = 0;
                break;

                case SDL_BUTTON_RIGHT:
                    key = 1;
                break;

                case SDL_BUTTON_MIDDLE:
                    key = 2;
                break;
                }
            if(key > -1)
                {
                if(mButtons[key].state == SDL_RELEASED) return 1;
                mLastButton = mButtons[key];
                mButtons[key].state = SDL_RELEASED;
                mButtons[key].x = mEvent->get().button.x;
                mButtons[key].y = mEvent->get().button.y;
                }
            return 1;
            }
        else
            {
            for(int i=0; i<3; i++)
                {
                mButtons[i].state = SDL_RELEASED;
                }
            }
        }
    return 0;
    }

Mouse::Button Mouse::getButton(int id)
    {
    if(id == -1)
        {
        for(int i=0; i<3; i++)
            if(mButtons[i].state == SDL_PRESSED) return mButtons[i];
        }
    else
        {
        return mButtons[id];
        }
    }

void Mouse::warp(Uint32 x, Uint32 y)
    {
    mLastX = mX;
    mLastY = mY;
    mX = 0;
    mY = 0;
    return SDL_WarpMouse(mX,mY);
    }
