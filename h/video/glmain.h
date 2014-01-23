#ifndef _CAELISENGINE_OPENGLMAIN_
#define _CAELISENGINE_OPENGLMAIN_

#include "../CaelisEngine.h"

#include "glrender.h"

namespace Caelis
    {
    namespace Video
        {
        class CAELISENGINE_EXPORT OpenGLMain : public Caelis::Core::Patterns::ISingleton<OpenGLMain>
            {
            public:
                OpenGLMain();
                ~OpenGLMain();

                bool init();
                void kill();

                void step();
            };
        }
    }
#endif
