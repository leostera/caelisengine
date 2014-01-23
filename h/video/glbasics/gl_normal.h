#include "../../CaelisEngine.h"

namespace Caelis
    {
    namespace Video
        {
        namespace Basics
            {
            #ifndef _CAELISENGINE_NORMAL_
            #define _CAELISENGINE_NORMAL_
                template <class nType>
                class CAELISENGINE_EXPORT Normal
                    {
                    public:
                        Normal(Normal<nType> *normal);
                        Normal(nType x, nType y, nType z);
                        Normal();
                        ~Normal();

                    nType getVertex() const { return mVertex; }
                    nType getVertex(int id) const { return mVertex[id]; }
                        bool getStatus() const { return mBuilt; }
                    void normalize();

                        void setVertex(Vertex<nType>);
                        void set(nType x=0, nType y=0, nType z=0);
                        void copy(Normal<nType> *normal);


                    private:
                        Vertex<nType> *mVertex;
                        bool mBuilt;
                    };

                template <class nType>
                Normal<nType>::Normal(Normal<nType> *normal)
                    {
                    copy(normal);
                    mBuilt = true;
                    }

                template <class nType>
                Normal<nType>::Normal(nType x, nType y, nType z)
                    {
                    set(x,y,z);
                    mBuilt = true;
                    }

                template <class nType>
                Normal<nType>::Normal()
                    {
                    set();
                    }

                template <class nType>
                Normal<nType>::~Normal()
                    {

                    }

                template <class nType>
                void Normal<nType>::set(nType x, nType y, nType z)
                    {
                    if(!mVertex)
                        {
                        mVertex = new Vertex<nType>(x,y,z);
                        }
                    else
                        {
                        mVertex->set(x,y,z);
                        }
                    }

                template <class nType>
                void Normal<nType>::copy(Normal<nType> *normal)
                    {
                    if(!mVertex)
                        {
                        mVertex = new Vertex<nType>(normal->getVertex);
                        }
                    else
                        {
                        mVertex->copy(normal->getVertex());
                        }
                    }

                template <class nType>
                void Normal<nType>::normalize()
                    {
                    nType l = mVertex->getLength();
                    if(l != 0)
                        {
                        mVertex[0] /= l;
                        mVertex[1] /= l;
                        mVertex[3] /= l;
                        mVertex[3] /= l;
                        }
                    }
            #endif
            }
        }
    }

