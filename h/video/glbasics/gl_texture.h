#include "../../CaelisEngine.h"

namespace Caelis
    {
    namespace Video
        {
        namespace Basics
            {
            #ifndef _CAELISENGINE_GLTEXTURE_
            #define _CAELISENGINE_GLTEXTURE_
                class CAELISENGINE_EXPORT Texture
                    {
                    public:
                        Texture();
                        ~Texture();

                        void free();
                        void apply();

                        bool load(char *filename);
                        bool create(char *file);

                        GLuint get() { return mTexture; }
                        void set(GLuint tex) { mTexture = tex; }

                    private:
                        GLuint mTexture;
                        bool mUsing;
                    };
            #endif
            }
        }
    }




