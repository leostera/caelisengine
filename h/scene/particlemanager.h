#include "particlesys.h"

namespace Caelis
    {
    namespace Scene
        {
        #ifndef _CAELISENGINE_PARTICLEMANAGER_
        #define _CAELISENGINE_PARTICLEMANAGER_
            class CAELISENGINE_EXPORT ParticleManager : public Core::Patterns::ISingleton<ParticleManager>
                {
                private:
                    std::vector<CParticleSystem* >mSystems;

                public:
                    ParticleManager();
                    ~ParticleManager();

                    void add(CParticleSystem* sys);
                    void del(CParticleSystem* sys);

                    CParticleSystem* getNewSystem();

                    void step();
                };
        #endif
        }
    }
