#include "CaelisEngine.h"

namespace Caelis
    {
    namespace Net
        {
        #ifndef _CAELISENGINE_CLIENTSTATUS_
        #define _CAELISENGINE_CLIENTSTATUS_
            enum ClientStatus
                {
                CLIENT_IDLE=0,
                CLIENT_SENDING,
                CLIENT_RECEIVING,
                CLIENT_CONNECTED,
                CLIENT_NOTCONNECTED
                };
        #endif

        #ifndef _CAELISENGINE_CLIENT_
        #define _CAELISENGINE_CLIENT_

            class CAELISENGINE_EXPORT CClient
                {
                private:
                    Network* mNet;

                    Uint16 mChannel;
                    IPaddress mIp;
                    TCPsocket mTCP;
                    UDPsocket mUDP;
                    ClientStatus mStatus;

                    void * mTCPdata;
                    std::vector<UDPpacket*> mUDPpackets;

                public:
                    CClient();
                    ~CClient();

                    bool connectTCP(const char* ip, int port);
                    bool connectUDP(Uint16 port);
                    void disconnect();

                    void write(Uint16 value);
                    void write(Uint32 value);

                    Uint16 read16();
                    Uint32 read32();

                    void step();

                    void addTCPData(void* data);

                    void addUDPPacket(UDPpacket *packet);
                    void addUDPPackets(UDPpacket **packet);

                    UDPpacket** getPackets();
                    int getNumPackets() { return mUDPpackets.size(); }
                    TCPsocket getTCP() { return mTCP; }
                    UDPsocket getUDP() { return mUDP; }

                    void setChannel(Uint16 channel) { mChannel = channel; }
                };
        #endif

        };
    };
