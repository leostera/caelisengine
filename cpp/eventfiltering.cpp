#include "../h/CaelisEngine.h"

using namespace Caelis::Core::Input;

EventFiltering::EventFiltering()
    {
    mEvent = IEvent::getInstance();
    Log::getInstance()->write(2,"[EventFiltering]-> Singleton Created.");
    }

EventFiltering::~EventFiltering()
    {
    Log::getInstance()->write(2,"[EventFiltering]-> Singleton Destroyed.");
    mFilters.clear();
    }

void EventFiltering::addFilter(Uint8 eventType, int(*func)(), bool active)
    {
    Filter filter;
    filter.eventType = eventType;
    filter.active = active;
    if( (filter.function = func)==NULL) return;
    else mFilters.push_back( filter );
    }

void EventFiltering::deleteFilter(Uint8 eventType, int(*func)())
    {
    std::list<Filter>::iterator it;
    for(it = mFilters.begin(); it != mFilters.end(); it++)
        {
        if( (*it).eventType == eventType && (*it).function == func)
            {
            mFilters.erase(it);
            }
        }
    }

void EventFiltering::step()
    {
    std::list<Filter>::iterator it;

    if(mFilters.empty()) return;

    mEvent->poll();
        for(it = mFilters.begin(); it != mFilters.end(); it++)
            {
            if( (*it).eventType == mEvent->get().type && (*it).active == true)
                {
                if( (*it).function != NULL) (*it).function();
                }
            }
    }

