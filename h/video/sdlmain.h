#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Video
        {
        #ifndef _CAELISENGINE_SDLCONFIG_
        #define _CAELISENGINE_SDLCONFIG_
            struct CAELISENGINE_EXPORT SDLConfig
                {
                Uint32 Flags;       //SDL_Init(Flags);
                Uint32 VideoFlags;  //SDL_SetVideoMode(x,x,x, Flags);
                Uint32 VideoWidth;  //SDL_SetVideoMode(Width,x,x,x);
                Uint32 VideoHeight; //SDL_SetVideoMode(x,Height,x,x);
                Uint32 VideoBPP;    //SDL_SetVideoMode(x,x,BPP,x);
                };
        #endif

        #ifndef _CAELISENGINE_SDLMAIN_
        #define _CAELISENGINE_SDLMAIN_
            class CAELISENGINE_EXPORT SDLMain : public Core::Patterns::ISingleton<SDLMain>
                {
                private:
                    //Private Properties And Methods For SDL Functions
                    SDLConfig *mConfig;
                    SDLConfig *mLastConfig;
                    SDL_Surface *mScreen;
                    bool mFullscreen;

                public:
                    SDLMain();
                    ~SDLMain();

                    //Public Properties And Methods For SDL Functions
                    Uint32 init(Uint32 SDLFlags, Uint32 SDLVideoFlags, Uint32 W, Uint32 H, Uint32 BPP);
                    Uint32 changeVideoMode(Uint32 SDLVideoFlags, Uint32 W, Uint32 H, Uint32 BPP);
                    Uint32 resetVideoMode();

                    Uint32 iconifyWindow();
                    Uint32 switchFullscreen();

                    SDLConfig* getConfig();
                    void setConfig(SDLConfig *Config);
                    Uint32 applyConfig();

                    SDL_Surface* getScreen();
                    void blitToScreen(SDL_Surface* toBlit, SDL_Rect* RtoBlit=NULL, SDL_Rect* dest=NULL);
                    void fillScreen(Uint8 r=0, Uint8 g=0, Uint8 b=0, Uint8 a=255);

                    void setGLAttribute(SDL_GLattr attribute, Uint32 value);

                    void setCaption(const char * caption,...);
                    char** getCaption();

                    void updateScreen();
                };
        #endif
        }
    }
