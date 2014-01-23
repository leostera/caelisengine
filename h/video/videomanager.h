#ifndef _CAELISENGINE_VIDEOMANAGER_
#define _CAELISENGINE_VIDEOMANAGER_

#include "glmain.h"
#include "sdlmain.h"

namespace Caelis
    {
    namespace Video
        {
        class CAELISENGINE_EXPORT VideoManager : public Core::Patterns::ISingleton<VideoManager>
            {
            private:
                OpenGLMain* mGLmain;
                SDLMain* mSDLmain;

            public:
                VideoManager();
                ~VideoManager();

                SDLMain* getSDL();
                OpenGLMain* getGL();

                void render();
            };
        }
    }
#endif
