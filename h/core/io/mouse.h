#ifndef _CAELISENGINE_MOUSE_
#define _CAELISENGINE_MOUSE_

#include "../../CaelisEngine.h"

#include "../patterns/singleton.h"


namespace Caelis
    {
    namespace Core
        {
        namespace Input
            {
            class CAELISENGINE_EXPORT Mouse : public Core::Patterns::ISingleton<Mouse>
                {
                private:
                    IEvent* mEvent;

                    Uint32 mX;
                    Uint32 mY;
                    Uint32 mLastX;
                    Uint32 mLastY;
                    Uint32 mState;

                    struct Button
                        {
                        int button;
                        int x,y;
                        int state;
                        };

                    Button mButtons[3];
                    Button mLastButton;

                public:
                    Mouse();
                    ~Mouse();

                    Uint32 step();
                    void warp(Uint32 x, Uint32 y);

                    Uint32 getState() { return mState; }
                    Button getButton(int id=-1);
                    Button getLastButton() { return mLastButton; }
                    Uint32 getX() { return mX; }
                    Uint32 getY() { return mY; }
                    Uint32 getLastX() { return mLastX; }
                    Uint32 getLastY() { return mLastY; }
                };
            }
        }
    }
#endif
