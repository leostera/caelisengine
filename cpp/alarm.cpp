
#include "../h/CaelisEngine.h"

using namespace Caelis::Core::Time;

CAlarm::CAlarm( void (*callback)(void), Uint32 delay, bool isFrame)
    {
    mTimer = Timer::getInstance();
    setCallBack(callback);
    if(isFrame) setDelayInMiliseconds(delay);
    else setDelayInFrames(delay);
    mIsFrame=isFrame;
    mTime = 0;
    }

CAlarm::~CAlarm()
    {

    }

void CAlarm::setCallBack( void(*callback)(void) )
    {
    if(callback != NULL)CallBack = callback;
    }

void CAlarm::setDelayInMiliseconds(Uint32 miliseconds)
    {
    mDelay = miliseconds;
    }

void CAlarm::setDelayInFrames(Uint32 frames)
    {
    mDelay = frames;
    }

bool CAlarm::step()
    {
    if(!mIsFrame) mTimer->update();
    if(mIsFrame) mFrames += 1;
    else mTime += mTimer->getTimeSinceLastMeasure();
    if( (mIsFrame)?mFrames:mTime > mDelay)
        {
        if(CallBack != NULL) CallBack();
        if(mIsFrame) mFrames = 0;
        else mTime = 0;
        return true;
        }
    return false;
    }
