#ifndef _CAELISENGINE_JOYSTICK_
#define _CAELISENGINE_JOYSTICK_

#include "../../CaelisEngine.h"

#include "../patterns/singleton.h"


namespace Caelis
    {
    namespace Core
        {
        namespace Input
            {
            struct Button
                {
                Uint32 number;
                Uint32 status;
                };

            struct Ball
                {
                int deltaX;
                int deltaY;
                };

            struct Axe
                {
                Sint16 x;
                Sint16 y;
                Sint16 z;
                Sint16 w;
                };

            struct Stick
                {
                Uint32 status;
                Uint32 numHats;
                Uint32 numButtons;
                Uint32 numBalls;
                Uint32 numAxes;
                Uint8 hat;
                Button* buttons;
                Ball* balls;
                Axe* axes;
                SDL_Joystick* stick;
                char* name;
                };

            class CAELISENGINE_EXPORT Joystick : public Core::Patterns::ISingleton<Joystick>
                {
                private:
                    IEvent* mEvent;
                    Uint32 mNumJoysticks;

                    std::vector<Stick*> mSticks;

                public:
                    Joystick();
                    ~Joystick();

                    Stick* open(Uint32 number);
                    void close(Stick* joy);

                    Uint32 getNumJoysticks() { return mNumJoysticks; }

                    bool step();
                };
            }
        }
    }
#endif
