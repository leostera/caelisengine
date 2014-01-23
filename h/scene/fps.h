#ifndef _CAELISENGINE_FPS_
#define _CAELISENGINE_FPS_

#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Scene
        {
        class CAELISENGINE_EXPORT CFps
            {
            private:
                //Private Properties And Methods For Frames Per Second Handling
                Caelis::Core::Time::CAlarm* mAlarmFps;
                Uint32 mFps;
                Uint32 mShownFps;

                void reset();
            public:
                //Public Properties And Methods For Frames Per Second Handling
                CFps();
                ~CFps();

                Uint32 getFps() const { return mShownFps; }
                int step(void* data=NULL);
            };
        }
    }

#endif
