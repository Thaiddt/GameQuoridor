#include "ClientNetwork.h"

ClientNetwork::ClientNetwork(TcpSocket *socket){
    ClientNetwork::socket = socket;
}

void ClientNetwork::sendMessToServer(Packet &packet){
    if (packet.getDataSize() > 0 && ClientNetwork::getSocket()->send(packet) != sf::Socket::Done)
    {
        logl("Could not send packet");
    }
}

void ClientNetwork::recvMessToServer(Packet &packet)
{
    if (ClientNetwork::getSocket()->receive(packet) != sf::Socket::Done)
    {
        logl("Could not recv packet");
    }
}