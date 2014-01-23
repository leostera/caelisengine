#include "../../CaelisEngine.h"

namespace Caelis
    {
    namespace Video
        {
        namespace Basics
            {
            #ifndef _CAELISENGINE_UVMAP_
            #define _CAELISENGINE_UVMAP_
                template <class tType>
                class CAELISENGINE_EXPORT UVMap
                    {
                    public:
                        UVMap(UVMap<tType> *cuv);
                        UVMap(tType u, tType v);
                        UVMap();
                        ~UVMap();

                        void set(int id, tType value);
                        void copy(UVMap<tType> *cuv);
                        tType getU() const { return mUV[0]; }
                        tType getV() const { return mUV[1]; }

                        tType operator [] ( int id )
                            {
                            return mUV[id];
                            }

                    private:
                        tType mUV[2];
                    };

                template <class tType>
                UVMap<tType>::UVMap(UVMap<tType> *cuv)
                    {
                    copy(cuv);
                    }

                template <class tType>
                UVMap<tType>::UVMap(tType u, tType v)
                    {
                    set(0,u);
                    set(1,v);
                    }

                template <class tType>
                UVMap<tType>::UVMap()
                    {
                    set(0,0);
                    set(1,0);
                    }

                template <class tType>
                UVMap<tType>::~UVMap()
                    {

                    }

                template <class tType>
                void UVMap<tType>::copy(UVMap<tType> *cuv)
                    {
                    for(int i=0; i<2; i++)
                        this[i] = cuv[i];
                    }

                template <class tType>
                void UVMap<tType>::set(int id, tType value)
                    {
                    this[id] = value;
                    }
            #endif
            }
        }
    }
