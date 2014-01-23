#include "../h/CaelisEngine.h"

using namespace Caelis::Net;

CClient::CClient()
    {
    mLog = Core::Log::CLog::getInstance();
    mUDP = NULL;
    mTCP = NULL;
    mStatus = CLIENT_NOTCONNECTED;
    }

CClient::~CClient()
    {
    disconnect();
    }

bool CClient::connectTCP(const char* ip, int port)
    {
    if(SDLNet_ResolveHost(&mIp,ip,port)==-1)
        {
        mLog->write(2,"[CClient]-> Couldn't resolve Host: %s\n", SDLNet_GetError());
        return false;
        }
    mTCP=SDLNet_TCP_Open(&mIp);
    if(!mTCP)
        {
        mLog->write(2,"[CClient]SDLNet_TCP_Open: %s\n", SDLNet_GetError());
        return false;
        }
    return true;
    }

bool CClient::connectUDP(Uint16 port)
    {
    mUDP = SDLNet_UDP_Open(port);
    if(!mUDP)
        {
        mLog->write(2,"[CClient]SDLNet_UDP_Open: %s\n", SDLNet_GetError());
        return false;
        }
    return true;
    }

void CClient::disconnect()
    {
    if(mUDP != NULL) SDLNet_UDP_Close(mUDP);
    if(mTCP != NULL) SDLNet_TCP_Close(mTCP);
    mUDP = NULL;
    mTCP = NULL;
    }

void CClient::step()
    {
    if(mTCP != NULL)
        {
        SDLNet_TCP_Send(mTCP, mTCPdata, sizeof(mTCPdata));
        SDLNet_TCP_Recv(mTCP, mTCPdata, reinterpret_cast<const unsigned int>(sizeof(mTCPdata)) );
        }
    else if(mUDP != NULL)
        {
        std::vector<UDPpacket*>::iterator i;
        for(i = mUDPpackets.begin(); i!= mUDPpackets.end(); i++)
            {
            SDLNet_UDP_Send(mUDP,mChannel,(*i));
            SDLNet_UDP_Recv(mUDP,(*i));
            }
        }
    }

void CClient::addTCPData(void* data)
    {
    if(data != NULL)
        mTCPdata = data;
    else
        return;
    }

void CClient::addUDPPacket(UDPpacket *packet)
    {
    if(packet != NULL)
        mUDPpackets.push_back(packet);
    else
        return;
    }

void CClient::addUDPPackets(UDPpacket **packet)
    {
    int i=0;
    while(packet[i] != NULL)
        {
        mUDPpackets.push_back(packet[i]);
        i++;
        }
    }

void CClient::write(Uint16 value)
    {
    SDLNet_Write16(value,mTCPdata);
    }

void CClient::write(Uint32 value)
    {
    SDLNet_Write32(value,mTCPdata);
    }

Uint16 CClient::read16()
    {
    return SDLNet_Read16(mTCPdata);
    }

Uint32 CClient::read32()
    {
    return SDLNet_Read32(mTCPdata);
    }

UDPpacket** CClient::getPackets()
    {
    UDPpacket** packets;
    std::vector<UDPpacket*>::iterator it;
    for(it = mUDPpackets.begin(); it != mUDPpackets.end(); it++)
        {
        for(int i=0; i<mUDPpackets.size(); i++)
            {
            packets[i] = (*it);
            }
        }
    if(packets != NULL) return packets;
    return NULL;
    }
