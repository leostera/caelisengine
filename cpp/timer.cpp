#include "../h/CaelisEngine.h"

using namespace Caelis::Core::Time;

Timer::Timer()
    {
    mCurrentTime = 0;
    mAppTime = 0;
    mFirstMeasure = 0;
    mSecondMeasure = 0;
    std::time(&mRawtime);
    mTimeinfo = std::localtime(&mRawtime);
    }

void Timer::applyDelay()
    {
    SDL_Delay(mDelay);
    }

Uint32 Timer::getAppTime()
    {
    std::time(&mRawtime);
    mTimeinfo = std::localtime(&mRawtime);
    return mAppTime;
    }

Uint32 Timer::getTime()
    {
    std::time(&mRawtime);
    mTimeinfo = std::localtime(&mRawtime);
    return mCurrentTime;
    }

const char* Timer::getAppTimeString()
    {
    mAppTimeString = mAppTime;
    return mAppTimeString.c_str();
    }

const char* Timer::getTimeString()
    {
	/*mTimeinfo = std::localtime(&mRawtime);
    mTimeString = itoa(mTimeinfo.tm_hour,NULL,1);
    mTimeString += ":";
    mTimeString += itoa(mTimeinfo.tm_min,NULL,1);
    mTimeString += ":";
    mTimeString += itoa(mTimeinfo.tm_sec,NULL,1);
    return mTimeString.c_str();*/
    }

Uint32 Timer::getHour()
    {
    std::time(&mRawtime);
    mTimeinfo = std::localtime(&mRawtime);
    return mTimeinfo->tm_hour;
    }

Uint32 Timer::getMin()
    {
    std::time(&mRawtime);
    mTimeinfo = std::localtime(&mRawtime);
    return mTimeinfo->tm_min;
    }

Uint32 Timer::getSec()
    {
    std::time(&mRawtime);
    mTimeinfo = std::localtime(&mRawtime);
    return mTimeinfo->tm_sec;
    }

void Timer::setDelayTime(Uint32 delay)
    {
    mDelay = delay;
    }

void Timer::update()
    {
    mAppTime += SDL_GetTicks();
    mFirstMeasure = mSecondMeasure;
	mSecondMeasure = SDL_GetTicks();
	std::time(&mRawtime);
	mTimeinfo = std::localtime(&mRawtime);
    }

Uint32 Timer::getTimeSinceLastMeasure()
    {
    std::time(&mRawtime);
    mTimeinfo = std::localtime(&mRawtime);
    //update();
    return (mSecondMeasure - mFirstMeasure);
    }

bool Timer::checkTime(Uint32 miliseconds)
    {
    return ((mSecondMeasure - mFirstMeasure)==miliseconds) ? true : false;
    }
