#ifndef _CAELISENGINE_ALARM_
#define _CAELISENGINE_ALARM_

#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Core
        {
        namespace Time
            {
            class CAELISENGINE_EXPORT CAlarm
                {
                private:
                    //Private Propierties And Methods For Alarm Use
                    Timer *mTimer;
                    Uint32 mDelay;
                    Uint32 mTime;
                    Uint32 mFrames;
                    bool mIsFrame;
                    void (*CallBack)(void);

                public:
                    //Public Propierties And Methods For Alarm Use
                    CAlarm( void (*callback)(void), Uint32 delay, bool isFrame=false);
                    ~CAlarm();

                    void setCallBack( void(*callback)(void));

                    void setDelayInMiliseconds(Uint32 miliseconds);
                    void setDelayInFrames(Uint32 frames);

                    bool step();
                };
            }
        }
    }

#endif
