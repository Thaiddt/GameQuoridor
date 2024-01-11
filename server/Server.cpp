#include "network/ServerNetwork.h"

int main(int argc, char *argv[])
{
    ServerNetwork server_network(5550);
    server_network.Run();
    return 0;
}