#ifndef _CAELISENGINE_LOG_
#define _CAELISENGINE_LOG_

#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Core
        {
        const int LOG_APP=1;
        const int LOG_CLIENT=2;
        const int LOG_SERVER=4;
        const int LOG_USER=8;

        class CAELISENGINE_EXPORT Log : public Core::Patterns::ISingleton<Log>
            {
            private:
                //Private Properties And Methods For The Logger
                std::ofstream mAppLog;
                std::ofstream mClientLog;
                std::ofstream mServerLog;

                std::vector<std::string> logStrings;
                bool loadStrings();

                Caelis::Core::Time::Timer *mTimer;

            public:
                Log();
                ~Log();

                //Public Properties And Methods For The Logger
                void write(Uint32 target, const char * Message, bool printTime=true, ...);
                void write(Uint32 target, unsigned long msgID, bool printTime=true, ...);

            };

        }
    }
#endif
