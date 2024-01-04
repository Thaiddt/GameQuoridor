#include "NetworkUtilsClient.hpp"

int main(int argc, char *argv[]){
    NetworkUtilsClient client_network;
    client_network.Connect("localHost", 5550);
    client_network.Run();
    return 0;
}