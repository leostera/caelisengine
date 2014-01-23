#ifndef _CAELISENGINE_RESOURCEMANAGER_
#define _CAELISENGINE_RESOURCEMANAGER_

#include "resource.h"
#include "gfx_image.h"
#include "gfx_sprite.h"
#include "sfx_sound.h"

namespace Caelis
    {
    namespace Resources
        {
        class CAELISENGINE_EXPORT ResourceManager : public Core::Patterns::ISingleton<ResourceManager>
            {
            private:
                std::vector<IResource*> mResources;

            public:
                ResourceManager();
                ~ResourceManager();

                IResource* getNew();
                void add(IResource* res);
                void kill(IResource* res);
            };
        }
    }
#endif
