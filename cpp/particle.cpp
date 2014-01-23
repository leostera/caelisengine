#include "../h/CaelisEngine.h"

using Caelis::Scene::CParticle;
using namespace Caelis::Video;

CParticle::CParticle(Basics::Vertex<GLfloat> pos,
            Basics::Vertex<GLfloat> dir,
            Basics::Vertex<GLfloat> grav,
            Basics::Color<GLfloat> color, GLfloat life, GLfloat fade, bool active, GLfloat speed)
    {
    mPos = pos;
    mDir = dir;
    mGravity = grav;
    mColor = color;
    mLife = mTempLife = life;
    mFadeTime = fade;
    mActive = active;
    mSpeed = speed;
    }

CParticle::~CParticle()
    {

    }

void CParticle::setPos(Basics::Vertex<GLfloat> pos)
    {
    mPos = pos;
    }

void CParticle::setDir(Basics::Vertex<GLfloat> dir)
    {
    mDir = dir;
    }

void CParticle::setGravity(Basics::Vertex<GLfloat> grav)
    {
    mGravity =grav;
    }

void CParticle::setColor(Basics::Color<GLfloat> color)
    {
    mColor = color;
    }

void CParticle::setFadeTime(GLfloat time)
    {
    mFadeTime = time;
    }

void CParticle::setLife(GLfloat life)
    {
    mLife = life;
    }

void CParticle::setActive(bool active)
    {
    mActive = active;
    }

void CParticle::kill()
    {
    mLife = mTempLife;
    mActive = true;
    }

void CParticle::update()
    {
    mPos.inc_x(mDir.x() * mSpeed + mGravity.x());
  	mPos.inc_y(mDir.y() * mSpeed + mGravity.y());
  	mPos.inc_z(mDir.z() * mSpeed + mGravity.z());

    mLife -= mFadeTime;

    if (mLife < 0.0f)
        {
        kill();
        }
    }
