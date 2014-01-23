#include "../h/CaelisEngine.h"

using namespace Caelis::Video;
using Caelis::Core::Log;

SDLMain::SDLMain()
    {
    mConfig = 0;
    Log::getInstance()->write(2,"[SDL]-> Singleton Created.");
    }

SDLMain::~SDLMain()
    {
    delete SDLMain::mConfig;
    Log::getInstance()->write(2,"[SDL]-> Singleton Destroyed.");
    SDL_Quit();
    }

Uint32 SDLMain::init(Uint32 SDLFlags, Uint32 SDLVideoFlags, Uint32 W, Uint32 H, Uint32 BPP)
    {
    mConfig = new SDLConfig;
    mConfig->Flags=SDLFlags;
    mConfig->VideoFlags=SDLVideoFlags;
    mConfig->VideoWidth=W;
    mConfig->VideoHeight=H;
    mConfig->VideoBPP=BPP;

    if(applyConfig())
        {
        return 1;
        }
    return 0;
    }

Uint32 SDLMain::resetVideoMode()
    {
    mConfig = mLastConfig;

    if(applyConfig())
        {
        Log::getInstance()->write(2,"[SDL]-> ResetVideoMode Changed Succesfully: %d x %d x %d",mConfig->VideoWidth,mConfig->VideoHeight,mConfig->VideoBPP);
        return 1;
        }
    return 0;
    }

Uint32 SDLMain::changeVideoMode(Uint32 SDLVideoFlags, Uint32 W, Uint32 H, Uint32 BPP)
    {
    mLastConfig = mConfig;
    mConfig->VideoFlags = SDLVideoFlags;
    mConfig->VideoWidth = W;
    mConfig->VideoHeight = H;
    mConfig->VideoBPP = BPP;

    if(applyConfig())
        {
        Log::getInstance()->write(2,"[SDL]-> VideoMode Changed Succesfully: %d x %d x %d",W,H,BPP);
        return 1;
        }
    return 0;
    }

Uint32 SDLMain::iconifyWindow()
    {
    if(!SDL_WM_IconifyWindow()) return 0;
    Log::getInstance()->write(2,"[SDL]-> window minimized.");
    return 1;
    }

Uint32 SDLMain::switchFullscreen()
    {
    if(!SDL_WM_ToggleFullScreen(mScreen)) return 0;
    Log::getInstance()->write(2,"[SDL]-> fullscreen switched.");
    return 1;
    }

SDLConfig* SDLMain::getConfig()
    {
    if( SDLMain::mConfig == 0 )
        {
        mConfig = new SDLConfig;
        Log::getInstance()->write(2,"[SDL]-> Blank Configuration Created - Warning: Must Set Configuration.");
        return mConfig;
        }
    else
        {
        return mConfig;
        }
    return NULL;
    }

void SDLMain::setConfig(SDLConfig *Config)
    {
    mConfig = Config;
    Log::getInstance()->write(2,"[SDL]-> Configuration Set.");
    }

Uint32 SDLMain::applyConfig()
    {
    if( SDLMain::mConfig == 0)
        {
        Log::getInstance()->write(2,"[SDL]-> Configuration Error: Configuration Struct Was Not Set.");
        return 0;
        }
    if(SDL_Init(mConfig->Flags)<0)
        {
        Log::getInstance()->write(2,"[SDL]-> Configuration Error: SDL Init Error: %s.", (SDL_GetError()!=NULL)?SDL_GetError():"Unable To Get SDL_GetError() Information");
        return 0;
        }
    if(mConfig->VideoFlags&SDL_OPENGL)
        {
        if(SDL_SetVideoMode(mConfig->VideoWidth, mConfig->VideoHeight, mConfig->VideoBPP, mConfig->VideoFlags)<0)
            {
            Log::getInstance()->write(2,"[SDL]-> Configuration Error: SDL SetVideoMode Error: %s.",(SDL_GetError()!=NULL)?SDL_GetError():"Unable To Get SDL_GetError() Information");
            return 0;
            }
        }
    else
        {
        if( (mScreen = SDL_SetVideoMode(mConfig->VideoWidth, mConfig->VideoHeight, mConfig->VideoBPP, mConfig->VideoFlags)) == NULL)
            {
            Log::getInstance()->write(2,"[SDL]-> Configuration Error: SDL SetVideoMode Error: %s.",(SDL_GetError()!=NULL)?SDL_GetError():"Unable To Get SDL_GetError() Information");
            return 0;
            }
        }

    if(mConfig->VideoFlags&SDL_FULLSCREEN) mFullscreen = true;
    else mFullscreen = false;

    /*if(!mFullscreen)
        SDL_WM_GrabInput(SDL_GRAB_ON);*/

    Log::getInstance()->write(2,"[SDL]-> Configuration Applied Succesfully: %d x %d x %d",mConfig->VideoWidth,mConfig->VideoHeight,mConfig->VideoBPP);

    atexit(SDL_Quit);

    return 1;
    }

SDL_Surface* SDLMain::getScreen()
    {
    return mScreen;
    }

void SDLMain::setGLAttribute(SDL_GLattr attribute, Uint32 value)
    {
    if(mConfig->VideoFlags&SDL_OPENGL) SDL_GL_SetAttribute(attribute,value);
    else return;
    }

void SDLMain::setCaption(const char * caption,...)
    {
    char string[1024];
    va_list ap;
    va_start(ap, caption);
    vsprintf(string, caption, ap);
    va_end(ap);
    SDL_WM_SetCaption(string,NULL);
    }

void SDLMain::updateScreen()
    {
    if(mConfig->VideoFlags&SDL_OPENGL) SDL_GL_SwapBuffers();
    else SDL_Flip(mScreen);
    }

void SDLMain::blitToScreen(SDL_Surface* toBlit, SDL_Rect* RtoBlit, SDL_Rect* dest)
    {
    SDL_BlitSurface(toBlit,RtoBlit,mScreen,dest);
    }

void SDLMain::fillScreen(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
    SDL_FillRect(mScreen,NULL,SDL_MapRGBA(mScreen->format,r,g,b,a));
    }

char** SDLMain::getCaption()
    {
    char** caption;
    SDL_WM_GetCaption(caption,NULL);
    return caption;
    }
