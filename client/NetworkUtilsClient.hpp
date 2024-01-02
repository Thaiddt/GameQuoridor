#pragma once

#include <SFML/Network.hpp>
#include <string>

class NetworkUtilsClient {
public:
    NetworkUtilsClient();
    ~NetworkUtilsClient();

    bool connectToServer(const std::string& serverAddress, unsigned short port);
    void sendMessage(const std::string& message);
    std::string receiveMessage();
    void disconnect();

private:
    sf::TcpSocket socket;
};