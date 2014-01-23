#include "../CaelisEngine.h"

#include "glbasics.h"

namespace Caelis
    {
    namespace Video
        {
        namespace Renderer
            {
            #ifndef _CAELISENGINE_OPENGLRENDERER_
            #define _CAELISENGINE_OPENGLRENDERER_
                class CAELISENGINE_EXPORT GLRenderer : public Core::Patterns::ISingleton<GLRenderer>
                    {
                    public:
                        GLRenderer();
                        ~GLRenderer();

                        void add(Caelis::Video::Basics::IRenderData *data);

                        void free(int id = -1);

                        void draw();

                    private:
                        std::vector<Caelis::Video::Basics::IRenderData *> mData;
                    };
            #endif
            }
        }
    }
