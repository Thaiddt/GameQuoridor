#include "NetworkUtilsServer.hpp"

int main(int argc, char *argv[])
{
    NetworkUtilsServer server_network(2525);
    server_network.Run();
    return 0;
}
