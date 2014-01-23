#include "../h/video/glrender.h"

using namespace Caelis::Video::Renderer;

GLRenderer::GLRenderer()
    {

    }

GLRenderer::~GLRenderer()
    {
    free(-1);
    }

void GLRenderer::add(Caelis::Video::Basics::IRenderData *data)
    {
    if(data != NULL)
        mData.push_back(data);
    else
        return;
    }

void GLRenderer::free(int id)
    {
    if(id == -1)
        {
        std::vector<Caelis::Video::Basics::IRenderData *>::iterator it;
        for(it = mData.begin(); it != mData.end(); it++)
            {
            delete (*it);
            (*it) = NULL;
            }
        mData.clear();
        return;
        }
    delete mData[id];
    }

void GLRenderer::draw()
    {
    std::vector<Caelis::Video::Basics::IRenderData *>::iterator it;
    for(it = mData.begin(); it != mData.end(); it++)
        {

        }
    }
