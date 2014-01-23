#ifndef _CAELISENGINE_INSTANCE_
#define _CAELISENGINE_INSTANCE_

#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Instance
        {
        class CAELISENGINE_EXPORT IInstance
            {
            private:
                Uint32 mId;
                Uint32 mDepth; //Usado para 2D, algo asi como la ID de la capa
                bool mVisible;
                std::string mName;

            public:
                IInstance() { mId = (int)this; }

                Uint32 getID() { return mId; }

                void setName(std::string Name) { mName = Name; }
                std::string getName() const { return mName; }

                void setVisible(bool visible) { mVisible = visible; }
                bool getVisible() const { return mVisible; }

                void setDepth(Uint32 depth) { mDepth = depth; }
                Uint32 getDepth() const { return mDepth; }

                virtual Uint32 create()=0;
                virtual Uint32 destroy()=0;
                virtual Uint32 keyPress(SDLKey key) {};
                virtual Uint32 keyRelease(SDLKey key) {};
                virtual Uint32 mouseMove() {};
                virtual Uint32 mousePress() {};
                virtual Uint32 mouseRelease() {};
                virtual Uint32 draw() {};
                virtual Uint32 step() {};
                virtual Uint32 collision() {};
            };
        }
    }
#endif
