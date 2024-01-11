#include "SFML/Network.hpp"
#include <iostream>

#define logl(x) std::cout << x << std::endl
#define log(x) std::cout << x

using namespace std;
using namespace sf;

class ClientNetwork
{
private:
    TcpSocket *socket;
public :
    TcpSocket *getSocket()
    {
        return socket;
    }

    ClientNetwork(TcpSocket *socket);
    void sendMessToServer(Packet &packet);
    void recvMessToServer(Packet &packet);
};