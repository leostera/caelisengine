#include "../h/CaelisEngine.h"

using namespace Caelis::Video::Basics;

Texture::Texture()
    {
    mTexture = 0;
    mUsing = false;
    }

Texture::~Texture()
    {
    free();
    }

void Texture::free()
    {
    if(mTexture != 0) glDeleteTextures(1, &mTexture);
    mTexture = 0;
    }

void Texture::apply()
    {
    if(!mUsing)
        {
        glBindTexture(GL_TEXTURE_2D,mTexture); mUsing = true;
        }
    else return;
    }

bool Texture::load(char *filename)
    {
    SDL_Surface *surface;
    int mode;

    surface = IMG_Load(filename);
     if (!surface) {
         return false;
     }

    if (surface->format->BytesPerPixel == 3) {

            mode = GL_RGB;

    } else if (surface->format->BytesPerPixel == 4) {

            mode = GL_RGBA;

    } else {

            SDL_FreeSurface(surface);
            return 0;

    }

    glGenTextures(1, &mTexture);

    glBindTexture(GL_TEXTURE_2D, mTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    SDL_FreeSurface(surface);

    return true;
    }
