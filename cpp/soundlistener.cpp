#include "../h/CaelisEngine.h"

using namespace Caelis::Audio::Basics;

CSoundListener::CSoundListener()
    {

    }

CSoundListener::CSoundListener(ALfloat pos[3], ALfloat vel[3], ALfloat orientation[6], ALfloat gain)
    {
    mPosition[0] = pos[0];
    mPosition[1] = pos[1];
    mPosition[2] = pos[2];
    mSpeed[0] = vel[0];
    mSpeed[1] = vel[1];
    mSpeed[2] = vel[2];
    mOrientation[0] = orientation[0];
    mOrientation[1] = orientation[1];
    mOrientation[2] = orientation[2];
    mGain = gain;
    }

CSoundListener::~CSoundListener()
    {
    ;
    }

void CSoundListener::setPosition(ALfloat vector[3])
    {
    mPosition[0] = vector[0];
    mPosition[1] = vector[1];
    mPosition[2] = vector[2];
    }

void CSoundListener::setSpeed(ALfloat vector[3])
    {
    mSpeed[0] = vector[0];
    mSpeed[1] = vector[1];
    mSpeed[2] = vector[2];
    }

void CSoundListener::setOrientation(ALfloat vector[6])
    {
    mOrientation[0] = vector[0];
    mOrientation[1] = vector[1];
    mOrientation[2] = vector[2];
    mOrientation[3] = vector[3];
    mOrientation[4] = vector[4];
    mOrientation[5] = vector[5];
    }

void CSoundListener::setPosition(ALfloat x,ALfloat y,ALfloat z)
    {
    mPosition[0] = x;
    mPosition[1] = y;
    mPosition[2] = z;
    }

void CSoundListener::setSpeed(ALfloat x,ALfloat y,ALfloat z)
    {
    mSpeed[0] = x;
    mSpeed[1] = y;
    mSpeed[2] = z;
    }

void CSoundListener::setOrientation(ALfloat x,ALfloat y,ALfloat z,ALfloat x2,ALfloat y2,ALfloat z2)
    {
    mOrientation[0] = x;
    mOrientation[1] = y;
    mOrientation[2] = z;
    mOrientation[3] = x2;
    mOrientation[4] = y2;
    mOrientation[5] = z2;
    }

void CSoundListener::setGain(ALfloat gain)
    {
    mGain = gain;
    }

void CSoundListener::apply()
    {
    alListenerf(AL_GAIN,mGain);
    alListenerfv(AL_POSITION,mPosition);
    alListenerfv(AL_VELOCITY,mSpeed);
    alListenerfv(AL_ORIENTATION,mOrientation);
    }
