#include "NetworkUtilsClient.hpp"

NetworkUtilsClient::NetworkUtilsClient() {}

NetworkUtilsClient::~NetworkUtilsClient() {
    disconnect();
}

bool NetworkUtilsClient::connectToServer(const std::string& serverAddress, unsigned short port) {
    return (socket.connect(serverAddress, port) == sf::Socket::Done);
}

void NetworkUtilsClient::sendMessage(const std::string& message) {
    sf::Packet packet;
    packet << message;
    socket.send(packet);
}

std::string NetworkUtilsClient::receiveMessage() {
    sf::Packet packet;
    socket.receive(packet);
    std::string receivedMessage;
    packet >> receivedMessage;
    return receivedMessage;
}

void NetworkUtilsClient::disconnect() {
    socket.disconnect();
}