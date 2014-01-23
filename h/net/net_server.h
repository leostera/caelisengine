#include "CaelisEngine.h"

namespace Caelis
    {
    namespace Net
        {
        #ifndef _CAELISENGINE_SERVERSTATUS_
        #define _CAELISENGINE_SERVERSTATUS_
            enum ServerStatus
                {
                SERVER_IDLE=0,
                SERVER_SENDING,
                SERVER_RECEIVING,
                SERVER_OPENED,
                SERVER_CLOSED
                };
        #endif

        #ifndef _CAELISENGINE_SERVER_
        #define _CAELISENGINE_SERVER_
            class CAELISENGINE_EXPORT CServer
                {
                private:
                    TCPsocket mTCP;
                    UDPsocket mUDP;
                    SDLNet_SocketSet mSocketSet;
                    Uint32 mSocketTimeOut;
                    char* type[4];

                    ServerStatus mStatus;

                    std::vector<int> mChannels;
                    IPaddress mIp;
                    std::vector<CClient*> mConnectedClients;
                    int mMaxClients;

                public:
                    CServer();
                    ~CServer();

                    bool create(const char* type="TCP", int port=666, int maxclients=24);
                    void close();

                    int addClient(CClient* client);
                    void deleteClient(int id);
                    void deleteAllClients();

                    void setSocketTimeout(Uint32 milliseconds);

                    void step();
                };
        #endif

        };
    };

