#ifndef _CAELISENGINE_SPRITE_
#define _CAELISENGINE_SPRITE_

#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Resources
        {
        enum CaelisEngine_ESPRITESTATUS
            {
            CAELISENGINE_SPRITE_STATUS_PLAYING=0,
            CAELISENGINE_SPRITE_STATUS_PAUSED,
            CAELISENGINE_SPRITE_STATUS_STOPPED,
            CAELISENGINE_SPRITE_STATUS_FF,
            CAELISENGINE_SPRITE_STATUS_RW
            };


        class CAELISENGINE_EXPORT CSprite : public IResource
            {
            private:
                CImage *mFrames[];
                Uint32 mFixedFrame;
                CaelisEngine_ESPRITESTATUS mStatus;
                Uint32 mCurrentFrame;
                Uint32 mMaxFrame;
                static const Uint32 mMinFrame=0;
                bool mBuilt;

            public:
                CSprite(CImage* frames);
                CSprite(const char * TileSetFileName, Uint32 w, Uint32 h, Uint32 separation, Uint32 amount);
                CSprite(const char * SprFileName);
                ~CSprite();

                Uint32 setFixedFrame(Uint32 value);
                Uint32 getFixedFrame() { return mFixedFrame; }

                CaelisEngine_ESPRITESTATUS getStatus() { return mStatus; }
                void setStatus(CaelisEngine_ESPRITESTATUS status);

                void freeSprite();
                void freeFrame(Uint32 frame);

                bool loadSprite(CImage* frames);
                bool loadSprite(const char * TileSetFileName, Uint32 w, Uint32 h, Uint32 separation, Uint32 amount);
                bool loadSprite(const char * SprFileName);

                CImage* getCurrentFrame() { return mFrames[mCurrentFrame]; }
                CImage* getConstCurrentFrame() const { return mFrames[mCurrentFrame]; }
            };
        }
    }
#endif
