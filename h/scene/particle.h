#include "../CaelisEngine.h"

#include "../video/glbasics/gl_vector.h"
#include "../video/glbasics/gl_color.h"

namespace Caelis
    {
    namespace Scene
        {
        #ifndef _CAELISENGINE_PARTICLE_
        #define _CAELISENGINE_PARTICLE_
            class CAELISENGINE_EXPORT CParticle
                {
                private:
                    Video::Basics::Vertex<GLfloat> mPos;
                    Video::Basics::Vertex<GLfloat> mDir;
                    Video::Basics::Vertex<GLfloat> mGravity;
                    Video::Basics::Color<GLfloat> mColor;

                    GLfloat mLife, mTempLife;
                    GLfloat mFadeTime;
                    GLfloat mSpeed;
                    bool mActive;

                public:
                    CParticle(Video::Basics::Vertex<GLfloat> pos,
                                Video::Basics::Vertex<GLfloat> dir,
                                Video::Basics::Vertex<GLfloat> grav,
                                Video::Basics::Color<GLfloat> color,
                                GLfloat life=1.0f,
                                GLfloat fade=0.1f,
                                bool active=true,
                                GLfloat speed=1.0f);
                    ~CParticle();

                    void setPos(Video::Basics::Vertex<GLfloat> pos);
                    void setDir(Video::Basics::Vertex<GLfloat> dir);
                    void setGravity(Video::Basics::Vertex<GLfloat> grav);
                    void setColor(Video::Basics::Color<GLfloat> color);
                    void setFadeTime(GLfloat time);
                    void setLife(GLfloat life);
                    void setActive(bool active);

                    Video::Basics::Vertex<GLfloat> getPos() { return mPos; }
                    Video::Basics::Vertex<GLfloat> getDir() { return mDir; }
                    Video::Basics::Vertex<GLfloat> getGravity() { return mGravity; }
                    Video::Basics::Color<GLfloat> getColor() { return mColor; }
                    GLfloat getLife() { return mLife; }
                    GLfloat getFadeTime() { return mFadeTime; }
                    bool getActive() { return mActive; }

                    void update();
                    void kill();
                };
        #endif
        }
    }
