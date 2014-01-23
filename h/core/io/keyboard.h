#ifndef _CAELISENGINE_KEYBOARD_
#define _CAELISENGINE_KEYBOARD_

#include "../../CaelisEngine.h"

#include "../patterns/singleton.h"


namespace Caelis
    {
    namespace Core
        {
        namespace Input
            {
            class CAELISENGINE_EXPORT Keyboard : public Core::Patterns::ISingleton<Keyboard>
                {
                private:
                    IEvent* mEvent;

                    Uint8 *mKey;
                    SDLKey mLastKey;

                    struct Filter
                        {
                        SDLKey key;
                        SDLMod mod;
                        int(*function)();
                        bool active;
                        };

                    std::list<Filter> mFilters;

                public:
                    Keyboard();
                    ~Keyboard();

                    bool getKey(SDLKey key, bool up=true, SDLMod mod=KMOD_NONE);
                    SDLKey getLastKey();

                    void addFilter(SDLKey key, SDLMod mod, int(*func)(), bool active=true);
                    void deleteFilter(SDLKey key, SDLMod mod, int(*func)());

                    void step();
                };
            }
        }
    }
#endif
