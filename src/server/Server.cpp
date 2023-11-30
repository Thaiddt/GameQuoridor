// Server.cpp
#include "Server.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

Server::Server(int port) : port(port), running(false) {}

Server::~Server() {
    Stop();
}

void Server::Start() {
    running = true;
    std::thread(&Server::ListenForClients, this).detach();
}

void Server::Stop() {
    running = false;
    close(serverSocket);
}

void Server::ListenForClients() {
    // Set up the server socket and start listening
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating server socket." << std::endl;
        return;
    }

    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error binding server socket." << std::endl;
        close(serverSocket);
        return;
    }

    if (listen(serverSocket, SOMAXCONN) == -1) {
        std::cerr << "Error listening on server socket." << std::endl;
        close(serverSocket);
        return;
    }

    // Handle incoming connections and create threads to handle each client
    // See: accept()
}

void Server::HandleClient(int clientSocket) {
    // Handle communication with a single client
    // See: send(), recv()
}

void Server::BroadcastMessage(const Message& message) {
    // Send the message to all connected clients
}
