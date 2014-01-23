#include "../h/CaelisEngine.h"

using namespace Caelis::Core;
using Caelis::Core::Time::Timer;

Log::Log()
    {
    mAppLog.open("CaelisEngine_AppLog.log");
    mClientLog.open("CaelisEngine_ClientLog.log");
    mServerLog.open("CaelisEngine_ServerLog.log");

    if(!loadStrings()) write(1,"Impossible To Load Strings.\n");

    mTimer = Timer::getInstance();

    char *Copyright ="|*****************************************************|\n"
                     "|                                                     |\n"
                     "|                  BUILDSTAMP                         |\n"
                     "|              Copyright (C) 2005-2006                |\n"
                     "|                                                     |\n"
                     "|*****************************************************|\n\n";

    write(2,Copyright,false);
    write(4,Copyright,false);

    write(2,"[Log]-> Singleton Created.");
    }

Log::~Log()
    {
    write(2,"[Log]-> Singleton Destroyed.");
    }

void Log::write(Uint32 target, const char * Message, bool printTime, ...)
    {
    char string[1024];
    va_list ap;
    va_start(ap, Message);
    vsprintf(string, Message, ap);
    va_end(ap);

    if(target&LOG_APP)
       {
       if(printTime) mAppLog<<"["<<mTimer->getHour()<<":"<<mTimer->getMin()<<":"<<mTimer->getSec()<<"]-";
       mAppLog<<string<<"\n\n";
       mAppLog.flush();
       }
   if(target&LOG_CLIENT)
       {
       if(printTime) mClientLog<<"["<<mTimer->getHour()<<":"<<mTimer->getMin()<<":"<<mTimer->getSec()<<"]-";
       mClientLog<<string<<"\n\n";
       mClientLog.flush();
       }
   if(target&LOG_SERVER)
       {
       if(printTime) mServerLog<<"["<<mTimer->getHour()<<":"<<mTimer->getMin()<<":"<<mTimer->getSec()<<"]-";
       mServerLog<<string<<"\n\n";
       mServerLog.flush();
       }
   if(target&LOG_USER)
       {
    #ifdef _WIN32
       MessageBox(NULL,string,"Message",MB_OK);
    #else
        #error User-level logging is not yet implemented for this platform.
    #endif
        }
    }

void Log::write(Uint32 target, unsigned long msgID, bool printTime, ...)
   {
   va_list args;
   va_start(args, logStrings[msgID]);
   char szBuf[1024];
   vsprintf(szBuf,logStrings[msgID].c_str(),args);
   va_end(args);
   write(target,szBuf);
   }

bool Log::loadStrings()
    {
#ifdef _WIN32

#else

#endif
    }
