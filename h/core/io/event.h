#ifndef _CAELISENGINE_EVENT_
#define _CAELISENGINE_EVENT_

#include "../../CaelisEngine.h"

namespace Caelis
    {
    namespace Core
        {
        namespace Input
            {
            class CAELISENGINE_EXPORT IEvent : public Core::Patterns::ISingleton<IEvent>
                {
                protected:
                    SDL_Event mEvent;
                    bool mPumped;

                public:
                    IEvent();
                    virtual ~IEvent();

                    SDL_Event get();
                    void push(SDL_Event event);
                    void push();
                    bool poll();
                    void pump();
                };
            }
        }
    }

#endif
