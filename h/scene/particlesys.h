#ifndef _CAELISENGINE_PARTICLESYSTEM_
#define _CAELISENGINE_PARTICLESYSTEM_

#include "../video/glbasics/gl_texture.h"
#include "particle.h"

namespace Caelis
    {
    namespace Scene
        {
        class CAELISENGINE_EXPORT CParticleSystem
            {
            private:
                std::vector<CParticle*> mParticles;
                CParticle* mBaseParticle;
                Video::Basics::Texture mTexture;
                bool mActive;
                bool mVisible;

            public:
                CParticleSystem(CParticle* base,char*bmp, Uint32 cant=0);
                CParticleSystem();
                ~CParticleSystem();

                bool step();

                bool init(CParticle* base, Uint32 cant=0);
                void reset();

                void setBase(CParticle* part);
                int add(CParticle* part);
                int add(std::vector<CParticle*> part);

                CParticle* getNewParticle();

                Video::Basics::Texture getTexture() { return mTexture; }

                bool isActive() { return mActive; }
                bool isVisible() { return mVisible; }

                void setVisible(bool visible) { mVisible = visible; }
                void setActive(bool active) { mActive = active; }
            };
        }
    }
#endif
