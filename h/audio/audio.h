#ifndef _CAELISENGINE_OPENALMAIN_
#define _CAELISENGINE_OPENALMAIN_

#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Audio
        {
        class CAELISENGINE_EXPORT OpenALMain : public Core::Patterns::ISingleton<OpenALMain>
            {
            private:
                Caelis::Audio::Basics::CSoundListener* mListener;
                ALCdevice *mDevice;

            public:
                OpenALMain();
                ~OpenALMain();

                bool init();
                void kill();

                void changeDevice(ALCubyte * device);

                void activateContext(ALCcontext * context);
                void suspendContext(ALCcontext * context);
                void killContext(ALCcontext * context);
                ALCcontext* createContext(int * attributes);
                ALCcontext* getActiveContext();
                ALCcontext* getNewContext();

                ALCenum getError();

                Caelis::Audio::Basics::CSoundListener* getListener() { return mListener; }

                void enable(ALenum capability);
                void disable(ALenum capability);
            };
        }
    }
#endif
