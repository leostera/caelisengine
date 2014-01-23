#include "../h/CaelisEngine.h"

using namespace Caelis::Resources;
using Caelis::Core::Log;

CSoundSample::CSoundSample(const char *filename)
    {
    load(filename);
    }

CSoundSample::~CSoundSample()
    {
    free();
    }

void CSoundSample::free()
    {
    alDeleteBuffers(1,&mBuffer);
    alDeleteSources(1,&mSource);
    }

void CSoundSample::load(const char *filename)
    {
    mBuffer = alutCreateBufferFromFile(filename);
    switch (mBuffer)
        {
        //error checking del valor devuelto por alutCreateBufferFromFile(const char*);
        //ver documentacion de OpenAL

        default:
            alGenSources(1,&mSource);

            alSourcei (mSource, AL_BUFFER, mBuffer);
            alSourcef (mSource, AL_PITCH, 1.0f);
            alSourcef (mSource, AL_GAIN, 1.0f);
            alSourcefv(mSource, AL_POSITION, mSourcePosition);
            alSourcefv(mSource, AL_VELOCITY, mSourceSpeed);
            alSourcei (mSource, AL_LOOPING, AL_FALSE);

            if(alGetError()==AL_NO_ERROR)
                {
                return;
                }
        break;
        }
    }

void CSoundSample::setSourcePosition(ALfloat x,ALfloat y,ALfloat z)
    {
    mSourcePosition[0] = x;
    mSourcePosition[1] = y;
    mSourcePosition[2] = z;
    }

void CSoundSample::setSourcePosition(ALfloat vector[3])
    {
    mSourcePosition[0] = vector[0];
    mSourcePosition[1] = vector[1];
    mSourcePosition[2] = vector[2];
    }

void CSoundSample::setSourceSpeed(ALfloat x,ALfloat y,ALfloat z)
    {
    mSourceSpeed[0] = x;
    mSourceSpeed[1] = y;
    mSourceSpeed[2] = z;
    }

void CSoundSample::setSourceSpeed(ALfloat vector[3])
    {
    mSourceSpeed[0] = vector[0];
    mSourceSpeed[1] = vector[1];
    mSourceSpeed[2] = vector[2];
    }

void CSoundSample::play()
    {
    alSourcePlay(mSource);
    }

void CSoundSample::pause()
    {
    alSourcePause(mSource);
    }

void CSoundSample::stop()
    {
    alSourceStop(mSource);
    }
