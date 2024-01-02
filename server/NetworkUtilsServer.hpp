#pragma once

#include <SFML/Network.hpp>
#include <vector>
#include <string>

class NetworkUtilsServer {
public:
    NetworkUtilsServer();
    ~NetworkUtilsServer();

    bool startServer(unsigned short port);
    void handleConnections();
    void sendMessage(sf::TcpSocket& clientSocket, const std::string& message);
    std::string receiveMessage(sf::TcpSocket& clientSocket);
    void disconnectClient(sf::TcpSocket& clientSocket);

private:
    sf::TcpListener listener;
    std::vector<sf::TcpSocket> connectedClients;
};