#include "../h/CaelisEngine.h"

using namespace Caelis::Core::Multithread;

MultithreadMain::MultithreadMain()
    {
    Log::getInstance()->write(2,"[CMultiThreading]-> Singleton Created.");
    }

MultithreadMain::~MultithreadMain()
    {
    Log::getInstance()->write(2,"[CMultiThreading]-> Singleton Destroyed.");
    waitAllThreads();
    killAllThreads();
    for(unsigned int i=0; i<mMutexs.size(); i++)
        {
        SDL_DestroyMutex( mMutexs.at(i) );
        }
    mMutexs.clear();
    }

SDL_Thread* MultithreadMain::addThread(int (*name)(void*), void* data)
    {
    SDL_Thread* t= SDL_CreateThread(name, data);
    mThreads.push_back(t);
    Log::getInstance()->write(2,"[CMultiThreading]-> added a Thread.");
    return t;
    }

void MultithreadMain::deleteThread(SDL_Thread* name)
    {
    if(mThreads.empty())
        {
        Log::getInstance()->write(2,"[CMultiThreading]-> no threads to kill.");
        return;
        }
    std::vector<SDL_Thread*>::iterator it;
    for(it = mThreads.begin(); it != mThreads.end(); it++)
        {
        if( (*it) == name)
            {
            SDL_KillThread( (*it) );
            mThreads.erase(it);
            (*it) = NULL;
            Log::getInstance()->write(2,"[CMultiThreading]-> a thread was killed.");
            break;
            }
        }
    }

void MultithreadMain::waitForThread(SDL_Thread* name, int* status)
    {
    std::vector<SDL_Thread*>::iterator it;

    for(it = mThreads.begin(); it != mThreads.end(); it++)
        {
        if( (*it) == name)
            {
            SDL_WaitThread( (*it),status );
            break;
            }
        }
    }

void MultithreadMain::waitAllThreads()
    {
    std::vector<SDL_Thread*>::iterator it;

    for(it = mThreads.begin(); it != mThreads.end(); it++)
        {
        SDL_WaitThread( (*it),NULL);
        mThreads.erase(it);
        (*it) = NULL;
        }
    }

void MultithreadMain::killAllThreads()
    {
    std::vector<SDL_Thread*>::iterator it;

    for(it = mThreads.begin(); it != mThreads.end(); it++)
        {
        SDL_KillThread( (*it) );
        mThreads.erase(it);
        (*it) = NULL;
        }
    }

int MultithreadMain::addMutex()
    {
    SDL_mutex* mut = SDL_CreateMutex();
    mMutexs.push_back(mut);
    for(unsigned int i=0; i<mMutexs.size(); i++)
        if(mMutexs[i]=mut) return i;
    return -1;
    }

void MultithreadMain::deleteMutex(int id)
    {
    if(mMutexs.empty())
        {
        Log::getInstance()->write(2,"[CMultiThreading]-> no mutexs to kill.");
        return;
        }
    SDL_DestroyMutex( mMutexs.at(id) );
    Log::getInstance()->write(2,"[CMultiThreading]-> a mutex was killed.");
    }

void MultithreadMain::lockMutex(int id)
    {
    if(mMutexs.empty())
        {
        Log::getInstance()->write(2,"[CMultiThreading]-> no mutexs to lock.");
        return;
        }
    SDL_mutexP( mMutexs.at(id) );
    Log::getInstance()->write(2,"[CMultiThreading]-> a mutex was locked.");
    }

void MultithreadMain::unlockMutex(int id)
    {
    if(mMutexs.empty())
        {
        Log::getInstance()->write(2,"[CMultiThreading]-> no mutexs to unlock.");
        return;
        }
    SDL_mutexV( mMutexs.at(id) );
    Log::getInstance()->write(2,"[CMultiThreading]-> a mutex was unlocked.");
    }
