#include "../CaelisEngine.h"

#include "patterns/singleton.h"

namespace Caelis
    {
    namespace Core
        {
        namespace Time
            {
            #ifndef _CAELISENGINE_TIMER_
            #define _CAELISENGINE_TIMER_
                class CAELISENGINE_EXPORT Timer : public Core::Patterns::ISingleton<Timer>
                    {
                    private:
                        std::time_t mRawtime;
                        std::tm *mTimeinfo;
                        Uint32 mFirstMeasure;
                        Uint32 mSecondMeasure;
                        Uint32 mCurrentTime;
                        Uint32 mAppTime;
                        Uint32 mDelay;

                        std::string mTimeString;
                        std::string mAppTimeString;

                    public:
                        Timer();

                        //Public Propierties And Methods For Timer Functions
                        bool checkTime(Uint32 miliseconds);

                        Uint32 getTimeSinceLastMeasure();
                        Uint32 getTime();
                        Uint32 getAppTime();
                        Uint32 getHour();
                        Uint32 getMin();
                        Uint32 getSec();

                        const char* getTimeString();
                        const char* getAppTimeString();

                        void setDelayTime(Uint32 delay);
                        void applyDelay();

                        void update();
                    };
            #endif
            }
        }
    }
