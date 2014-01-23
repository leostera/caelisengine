#ifndef _CAELISENGINE_MULTI_THREADING
#define _CAELISENGINE_MULTI_THREADING

#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Core
        {
        namespace Multithread
            {
            class CAELISENGINE_EXPORT MultithreadMain : public Core::Patterns::ISingleton<MultithreadMain>
                {
                private:
                    std::vector<SDL_Thread*> mThreads;
                    std::vector<SDL_mutex*> mMutexs;

                public:
                    MultithreadMain();
                    ~MultithreadMain();

                    SDL_Thread* addThread( int (*THREADName)(void*), void* THREADData = NULL);
                    void deleteThread(SDL_Thread* name);
                    void waitForThread(SDL_Thread* name, int* status = 0);

                    void waitAllThreads();
                    void killAllThreads();

                    int addMutex();
                    void deleteMutex(int id);
                    void lockMutex(int id);
                    void unlockMutex(int id);
                };
            }
        }
    }
#endif
