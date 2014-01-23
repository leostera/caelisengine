#ifndef _CAELISENGINE_SOUNDLISTENER_
#define _CAELISENGINE_SOUNDLISTENER_

#include "../../CaelisEngine.h"

namespace Caelis
    {
    namespace Audio
        {
        namespace Basics
            {
            class CAELISENGINE_EXPORT CSoundListener
                {
                private:
                    ALfloat mPosition[3];
                    ALfloat mSpeed[3];
                    ALfloat mOrientation[6];
                    ALfloat mGain;

                public:
                    CSoundListener();
                    CSoundListener(ALfloat pos[3], ALfloat vel[3], ALfloat orientation[6], ALfloat gain);
                    ~CSoundListener();

                    void setPosition(ALfloat x,ALfloat y,ALfloat z);
                    void setSpeed(ALfloat x,ALfloat y,ALfloat z);
                    void setOrientation(ALfloat x,ALfloat y,ALfloat z,ALfloat x2,ALfloat y2,ALfloat z2);
                    void setPosition(ALfloat vector[3]);
                    void setSpeed(ALfloat vector[3]);
                    void setOrientation(ALfloat vector[6]);
                    void setGain(ALfloat gain);

                    ALfloat * getPosition() { return mPosition; }
                    ALfloat * getSpeed() { return mSpeed; }
                    ALfloat * getOrientation() { return mOrientation; }
                    ALfloat getGain() { return mGain; }

                    void apply();
                };
            }
        }
    }

#endif
