#include "../../CaelisEngine.h"

namespace Caelis
    {
    namespace Video
        {
        namespace Basics
            {
            #ifndef _CAELISENGINE_RENDERDATA_
            #define _CAELISENGINE_RENDERDATA_
                class CAELISENGINE_EXPORT IRenderData
                    {
                    public:
                        virtual void render()=0;
                        IRenderData()
                            {

                            }
                        virtual ~IRenderData()
                            {

                            }
                    };
            #endif
            }
        }
    }
