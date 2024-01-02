#include "NetworkUtilsServer.hpp"

NetworkUtilsServer::NetworkUtilsServer() {}

NetworkUtilsServer::~NetworkUtilsServer() {
    listener.close();
    for (sf::TcpSocket& clientSocket : connectedClients) {
        clientSocket.disconnect();
    }
}

bool NetworkUtilsServer::startServer(unsigned short port) {
    return (listener.listen(port) == sf::Socket::Done);
}

void NetworkUtilsServer::handleConnections() {
    while (true) {
        sf::TcpSocket newClient;
        if (listener.accept(newClient) == sf::Socket::Done) {
            connectedClients.push_back(newClient);
        }
    }
}

void NetworkUtilsServer::sendMessage(sf::TcpSocket& clientSocket, const std::string& message) {
    sf::Packet packet;
    packet << message;
    clientSocket.send(packet);
}

std::string NetworkUtilsServer::receiveMessage(sf::TcpSocket& clientSocket) {
    sf::Packet packet;
    clientSocket.receive(packet);
    std::string receivedMessage;
    packet >> receivedMessage;
    return receivedMessage;
}

void NetworkUtilsServer::disconnectClient(sf::TcpSocket& clientSocket) {
    auto it = std::find(connectedClients.begin(), connectedClients.end(), clientSocket);
    if (it != connectedClients.end()) {
        connectedClients.erase(it);
        clientSocket.disconnect();
    }
}