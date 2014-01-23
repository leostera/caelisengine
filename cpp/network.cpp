#include "../h/CaelisEngine.h"

using namespace Caelis::Net;

CNetwork::CNetwork()
    {
    mLog->getInstance();
    mLog->write(2,"[CNetwork]-> Singleton created.");
    }

CNetwork::~CNetwork()
    {
    mLog->write(2,"[CNetwork]-> Singleton destroyed.");
    }
