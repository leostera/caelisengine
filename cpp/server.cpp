#include "../h/CaelisEngine.h"

using namespace Caelis::Net;

CServer::CServer(){}
CServer::~CServer(){}

bool CServer::create(const char* type, int port, int maxclients)
    {
    mMaxClients = maxclients;
    mSocketSet = SDLNet_AllocSocketSet(mMaxClients);
    if(type == "TCP")
        {
        SDLNet_ResolveHost(&mIp,NULL,port);
        mTCP = SDLNet_TCP_Open(&mIp);
        return true;
        }
    else if(type == "UDP")
        {
        mUDP=SDLNet_UDP_Open(port);
        return true;
        }
    return false;

    }

void CServer::close()
    {
    std::vector<CClient*>::iterator i;
    for(i=mConnectedClients.begin(); i!=mConnectedClients.end(); i++)
        {
		if((*i)->getTCP()!=NULL) SDLNet_TCP_DelSocket(mSocketSet,(*i)->getTCP());
        if((*i)->getUDP()!=NULL) SDLNet_UDP_DelSocket(mSocketSet,(*i)->getUDP());
        (*i) = NULL ;
        }
    SDLNet_TCP_Close(mTCP);
    SDLNet_UDP_Close(mUDP);
    mTCP = NULL;
    mUDP = NULL;
    }

int CServer::addClient(CClient* client)
    {
    int i=mConnectedClients.size();
    if( (i++)>mMaxClients)
        {
        mConnectedClients.push_back(client);
        if(client->getTCP()!=NULL) SDLNet_TCP_AddSocket(mSocketSet,client->getTCP());
        if(client->getUDP()!=NULL) SDLNet_UDP_AddSocket(mSocketSet,client->getUDP());
        return 1;
        }
    return 0;
    }

void CServer::deleteClient(int id)
    {
    if(mConnectedClients.empty())
        {
        mLog->write(2,"[CServer]-> no clients to delete.");
        return;
        }
    if(mConnectedClients[id]->getTCP()!=NULL) SDLNet_TCP_DelSocket(mSocketSet,mConnectedClients[id]->getTCP());
    if(mConnectedClients[id]->getUDP()!=NULL) SDLNet_UDP_DelSocket(mSocketSet,mConnectedClients[id]->getUDP());
    mConnectedClients[id] = NULL;
    }

void CServer::deleteAllClients()
    {
    if(mConnectedClients.empty())
        {
        mLog->write(2,"[CServer]-> no clients to delete.");
        return;
        }
    std::vector<CClient*>::iterator i;
    for(i=mConnectedClients.begin(); i!=mConnectedClients.end(); i++)
        {
		if((*i)->getTCP()!=NULL) SDLNet_TCP_DelSocket(mSocketSet,(*i)->getTCP());
        if((*i)->getUDP()!=NULL) SDLNet_UDP_DelSocket(mSocketSet,(*i)->getUDP());
        (*i) = NULL ;
        }
    mConnectedClients.clear();
    mLog->write(2,"[CServer]-> deleted all clients.",true);
    }

void CServer::setSocketTimeout(Uint32 milliseconds)
    {
    SDLNet_CheckSockets(mSocketSet,milliseconds);
    }

void CServer::step()
    {
    std::vector<CClient*>::iterator i;
    TCPsocket tcp;
    UDPsocket udp;
    for(i=mConnectedClients.begin(); i!=mConnectedClients.end(); i++)
        {
        tcp = (*i)->getTCP();
        udp = (*i)->getUDP();
		if(tcp !=NULL) SDLNet_TCP_Recv( tcp, reinterpret_cast<void*>((*i)->read32()), sizeof( (*i)->read32() ) );
        if(udp!=NULL) SDLNet_UDP_RecvV(udp,(*i)->getPackets());
        if(tcp!=NULL) SDLNet_TCP_Send(tcp,(void*)((*i)->read32()),sizeof((*i)->read32())+1);
        if(udp!=NULL) SDLNet_UDP_SendV(udp,(*i)->getPackets(),(*i)->getNumPackets());
        }
    }
