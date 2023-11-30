// Server.hpp
#pragma once

#include <vector>
#include <thread>
#include <mutex>
#include "Message.hpp"

class Server {
public:
    Server(int port);
    ~Server();

    void Start();
    void Stop();

private:
    int port;
    bool running;
    int serverSocket;
    std::vector<std::thread> clientThreads;
    std::mutex mutex;

    void ListenForClients();
    void HandleClient(int clientSocket);
    void BroadcastMessage(const Message& message);
};
