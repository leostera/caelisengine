#ifndef _CAELISENGINE_IMAGE_
#define _CAELISENGINE_IMAGE_

#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Resources
        {
        class CAELISENGINE_EXPORT CImage : public IResource
            {
            private:
                SDL_Surface *mImage;
                SDL_Rect mRect;
                Uint32 mAlpha;
                bool mBuilt;

            public:
                CImage(CImage* image);
                CImage(const char * ImageFile, Uint32 alpha = 255);

                ~CImage();

                SDL_Surface* getSurface() { return mImage; }
                SDL_Surface* getConstSurface() const { return mImage; }

                SDL_Rect getRect() { return mRect; }
                SDL_Rect getConstRect() const { return mRect; }

                void setAlpha(Uint32 value=255);
                Uint32 getAlpha() { return mAlpha; }

                Uint32 getPixel(Uint32 x, Uint32 y);
                void getPixel(Uint32 x, Uint32 y, Uint32 *pixel);

                void putPixel(Uint32 x, Uint32 y, Uint32 r, Uint32 g, Uint32 b, Uint32 a);
            };
        }
    }
#endif
