#include "../../CaelisEngine.h"

namespace Caelis
    {
    namespace Video
        {
        namespace Basics
            {
            #ifndef _CAELISENGINE_GLIMAGE_
            #define _CAELISENGINE_GLIMAGE_
                struct CAELISENGINE_EXPORT GLImage
                    {
                    GLint sizeX, sizeY;
                    unsigned char *data;
                    };
            #endif
            }
        }
    }
