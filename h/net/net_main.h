#include "CaelisEngine.h"

namespace Caelis
    {
    namespace Net
        {
        #ifndef _CAELISENGINE_NETWORK_
        #define _CAELISENGINE_NETWORK_
            class CAELISENGINE_EXPORT Network : public Core::Patterns::ISingleton<Network>
                {
                public:
                    CNetwork();
                    ~CNetwork();

                };
        #endif
        }
    }
