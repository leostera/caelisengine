#include "../h/CaelisEngine.h"

using namespace Caelis::Video;
using Caelis::Core::Log;

OpenGLMain::OpenGLMain()
    {
    Log::getInstance()->write(2,"[OpenGLMain]-> Singleton created");
    };

OpenGLMain::~OpenGLMain()
    {
    Log::getInstance()->write(2,"[OpenGLMain]-> Singleton destroyed");
    Log::getInstance()->erase();
    };

bool OpenGLMain::init(GLvoid)
    {
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    Uint32 w= SDLMain::getInstance()->getConfig()->VideoWidth;
    Uint32 h= SDLMain::getInstance()->getConfig()->VideoHeight;

    glLoadIdentity();
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.5, 0.5 ,0.5, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glShadeModel(GL_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    Log::getInstance()->write(2,"[OpenGLMain]-> Initiliazation Completed Succesfully.");
    return true;
    }
