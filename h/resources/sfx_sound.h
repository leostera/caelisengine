#ifndef _CAELISENGINE_SOUNDSAMPLE_
#define _CAELISENGINE_SOUNDSAMPLE_

#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Resources
        {
        class CAELISENGINE_EXPORT CSoundSample : public IResource
            {
            private:
                ALenum mFormat;
                ALsizei mSize;
                ALvoid* mData;
                ALfloat mFrequency;
                ALboolean mLoop;
                ALuint mBuffer;
                ALuint mSource;
                ALfloat mSourcePosition[3];
                ALfloat mSourceSpeed[3];

            public:
                CSoundSample(const char *filename);
                ~CSoundSample();

                void free();

                void load(const char *filename);

                ALuint getBuffer() const { return mBuffer; }
                ALuint getSource() const { return mSource; }

                ALfloat getSourcePosition() const { return mSourcePosition[3]; }
                ALfloat getSourceSpeed() const { return mSourceSpeed[3]; }

                void setSourcePosition(ALfloat x,ALfloat y,ALfloat z);
                void setSourcePosition(ALfloat vector[3]);
                void setSourceSpeed(ALfloat x,ALfloat y,ALfloat z);
                void setSourceSpeed(ALfloat vector[3]);
                void setLoop(bool looping);
                void setPitch(float pitch);
                void setGain(float gain);

                void play();
                void pause();
                void stop();
            };
        }
    }
#endif
