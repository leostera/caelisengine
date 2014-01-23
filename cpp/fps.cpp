#include "../h/CaelisEngine.h"

using namespace Caelis::Scene;
using Caelis::Core::Time::CAlarm;

CFps::CFps()
    {
    mFps = 0;
    mAlarmFps = new CAlarm(NULL,1000);
    }

CFps::~CFps()
    {
    delete mAlarmFps;
    }

int CFps::step(void* data)
    {
    mFps++;
    if(mAlarmFps->step())
        {
        reset();
        return 1;
        }
    return 0;
    }

void CFps::reset()
    {
    mShownFps = mFps;
    mFps = 0;
    }
