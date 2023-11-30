// Client.cpp
#include "Client.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

Client::Client(const char* serverIp, int serverPort)
    : serverIp(serverIp), serverPort(serverPort), clientSocket(-1) {}

Client::~Client() {
    Disconnect();
}

void Client::Connect() {
    // Set up the client socket and connect to the server
    // See: socket(), connect()
    // Start a thread to receive messages from the server
}

void Client::Disconnect() {
    // Close the client socket
}

void Client::SendMove(int x, int y) {
    // Create a Message for the move and send it to the server
    // See: send()
}

void Client::ReceiveMessages() {
    // Continuously receive messages from the server
    // See: recv()
}
