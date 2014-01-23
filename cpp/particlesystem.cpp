#include "../h/CaelisEngine.h"

using namespace Caelis::Scene;

CParticleSystem::CParticleSystem(CParticle* base,char*bmp,Uint32 cant)
    {
    init(base,cant);
    if(bmp = "BUILT_IN")
        {
        int texWidth = 32;
        int texHeight = 32;
        GLubyte *texPixels, *p;
        int texSize;
        int i, j;
        int radius;

        texSize = texWidth*texHeight*4*sizeof(GLubyte);
        texPixels = (GLubyte *) malloc(texSize);
        p = texPixels;
        for (i=0; i<texHeight; ++i)
            {
            for (j=0; j<texWidth; ++j)
                {
                GLuint dist = (GLuint)hypot(float(i - (texHeight / 2)),float(j - (texWidth / 2)));
                float color = 255-(dist*1.8);
                if (color < 0) color = 0;
                p[0] = color;
                p[1] = color;
                p[2] = color;
                p[3] = color;
                p+=4;
                }
            }
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, texPixels);

        free(texPixels);
        }
    else
        {
        mTexture.load(bmp);
        }
    mActive = mVisible = true;
    }

CParticleSystem::CParticleSystem()
    {
    ;
    }

CParticleSystem::~CParticleSystem()
    {
    std::vector<CParticle*>::iterator i;
    for(i=mParticles.begin(); i!=mParticles.end(); i++)
        {
        delete (*i);
        (*i) = NULL;
        }
    mParticles.clear();
    mTexture.free();
    }

bool CParticleSystem::step()
    {
    std::vector<CParticle*>::iterator i;
    mTexture.apply();
    for(i=mParticles.begin(); i!=mParticles.end(); i++)
        {
        if( (*i)->getActive() )
            {
            if( mVisible )
                {
                glColor4f((*i)->getColor().getColor(0),
                            (*i)->getColor().getColor(1),
                            (*i)->getColor().getColor(2),
                            (*i)->getLife());
                glBegin(GL_TRIANGLE_STRIP);
                    glTexCoord2d(1,1);
                        glVertex3f((*i)->getPos().x()+0.5f,(*i)->getPos().y()+0.5f,(*i)->getPos().z());
                    glTexCoord2d(0,1);
                        glVertex3f((*i)->getPos().x()-0.5f,(*i)->getPos().y()+0.5f,(*i)->getPos().z());
                    glTexCoord2d(1,0);
                        glVertex3f((*i)->getPos().x()+0.5f,(*i)->getPos().y()-0.5f,(*i)->getPos().z());
                    glTexCoord2d(0,0);
                        glVertex3f((*i)->getPos().x()-0.5f,(*i)->getPos().y()-0.5f,(*i)->getPos().z());
                glEnd();
                }
            (*i)->update();
            }
        }
    }

bool CParticleSystem::init(CParticle* base, Uint32 cant)
    {
    for(int i=0; i<cant; i++)
        {
        mParticles.push_back(base);
        }
    }

void CParticleSystem::reset()
    {
    std::vector<CParticle*>::iterator i;
    for(i=mParticles.begin(); i!=mParticles.end(); i++)
        {
        (*i) = mBaseParticle;
        }
    }

void CParticleSystem::setBase(CParticle* part)
    {
    mBaseParticle = part;
    }

int CParticleSystem::add(CParticle* part)
    {
    mParticles.push_back(part);
    }

int CParticleSystem::add(std::vector<CParticle*> part)
    {
    std::vector<CParticle*>::iterator it;
    for(it=part.begin(); it!=part.end(); it++)
        {
        mParticles.push_back( (*it) );
        }
    }
