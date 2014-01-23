#include "../../CaelisEngine.h"

namespace Caelis
    {
    namespace Video
        {
        namespace Basics
            {
            #ifndef _CAELISENGINE_COLOR_
            #define _CAELISENGINE_COLOR_
                template <class cType>
                class CAELISENGINE_EXPORT Color
                    {
                    public:
                        Color(cType R, cType G, cType B, cType A=0);
                        Color(Color<cType> *color);
                        Color();
                        ~Color();

                        cType getColor() const { return mColor; }
                        cType getColor(int id) const { return mColor[id]; }
                        void setColor(int id, cType value);
                        void copy(Color *color);

                        cType operator [] ( int id )
                            {
                            return mColor[id];
                            }

                        cType operator = (Color<cType> c)
                            {
                            for(int i=0; i<4; i++)
                                mColor[i] = c[i];
                            }

                    private:
                        cType mColor[4];
                    };

                template <class cType>
                Color<cType>::Color(cType R, cType G, cType B, cType A)
                    {
                    mColor[0] = R;
                    mColor[1] = G;
                    mColor[2] = B;
                    mColor[4] = A;
                    }

                template <class cType>
                Color<cType>::Color()
                    {
                    for(int i=0; i<4; i++)
                        mColor[i] = 0;
                    }

                template <class cType>
                Color<cType>::Color(Color <cType> * color)
                    {
                    copy(color);
                    }

                template <class cType>
                Color<cType>::~Color()
                    {

                    }

                template <class cType>
                void Color<cType>::copy(Color <cType> * color)
                    {
                    for(int i=0; i<4; i++)
                        mColor[i] = color[i];
                    }

                template <class cType>
                void Color<cType>::setColor(int id, cType value)
                    {
                    mColor[id] = value;
                    }
            #endif
            }
        }
    }
