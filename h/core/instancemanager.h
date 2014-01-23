#ifndef _CAELISENGINE_INSTANCEHANDLER_
#define _CAELISENGINE_INSTANCEHANDLER_

#include "../CaelisEngine.h"

#include "instance_base.h"

namespace Caelis
    {
    namespace Instance
        {
        class CAELISENGINE_EXPORT InstanceManager : public Core::Patterns::ISingleton<InstanceManager>
            {
            private:
                //Private Properties And Methods For InstanceHandling Functions
                std::list<IInstance*> mInstances;
                Uint32 mInstanceNumber;

            public:
                InstanceManager();
                ~InstanceManager();

                //Public Properties And Methods For InstanceHandling Functions
                IInstance* get(Uint32 instanceID);
                void add(IInstance* instance);
                void drop(IInstance* instance);
                void deleteAll();

                void step();

                Uint32 getInstanceNumber() const { return mInstanceNumber; }
            };
        }
    }

#endif

