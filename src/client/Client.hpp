// Client.hpp
#pragma once

#include "Message.hpp" // Include your message definitions

class Client {
public:
    Client(const char* serverIp, int serverPort);
    ~Client();

    void Connect();
    void Disconnect();

    void SendMove(int x, int y);
    // Add more client-specific functions if needed

private:
    const char* serverIp;
    int serverPort;
    int clientSocket;

    void ReceiveMessages();
};
