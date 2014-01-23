#ifndef _CAELISENGINE_SCENEMANAGER_
#define _CAELISENGINE_SCENEMANAGER_

#include "fps.h"
#include "mesh.h"
#include "particlemanager.h"
/*
#include "nodemanager.h"
#include "...manager.h"
*/

namespace Caelis
    {
    namespace Scene
        {
        class CAELISENGINE_EXPORT SceneManager : public Core::Patterns::ISingleton<SceneManager>
            {
            private:
                ParticleManager* mParticleManager;

                /*
                NodeManager
                ...Manager
                */

            public:
                SceneManager();
                ~SceneManager();

                bool step();

                ParticleManager* getParticleManager();
                /*
                getNodeManager
                get...Manager
                */
            };
        }
    }

#endif
