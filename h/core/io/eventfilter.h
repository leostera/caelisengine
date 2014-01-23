#ifndef _CAELISENGINE_EVENTFILTERING_
#define _CAELISENGINE_EVENTFILTERING_

#include "../../CaelisEngine.h"

#include "../patterns/singleton.h"

namespace Caelis
    {
    namespace Core
        {
        namespace Input
            {
            class CAELISENGINE_EXPORT EventFiltering : public Core::Patterns::ISingleton<EventFiltering>
                {
                private:
                    IEvent* mEvent;

                    struct Filter
                        {
                        Uint8 eventType;
                        int(*function)();
                        bool active;
                        };

                    std::list<Filter> mFilters;

                public:
                    EventFiltering();
                    ~EventFiltering();

                    void addFilter(Uint8 eventType, int(*func)(), bool active=true);
                    void deleteFilter(Uint8 eventType, int(*func)());

                    void step();
                };
            }
        }
    }
#endif
