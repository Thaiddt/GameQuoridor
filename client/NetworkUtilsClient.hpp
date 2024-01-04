#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <SFML/Network.hpp>
#include "GameManager.hpp"

#define logl(x) std::cout << x << std::endl
#define log(x) std::cout << x

class NetworkUtilsClient{
    sf::TcpSocket socket;
    sf::Packet last_packet;

    bool isConnected = false;
public:
    NetworkUtilsClient();
    void Connect(const char *, unsigned short);
    void ReceivePackets(sf::TcpSocket *);
    void SendPacket(sf::Packet &);
    void Disconnected();
    void Run();
};
