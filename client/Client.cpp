#include "view/LoginUI.h"

enum Screen
{
    LOGIN,
    LOBBY,
    GAME,
};

int main(int argc, char *argv[]){
    //Connect to server
    TcpSocket socket;
    Socket::Status status = socket.connect("127.0.0.1", 5550);
    
    //Check connect
    if (status != sf::Socket::Done) return 1;
    logl("Connect to server successful");

    //Make MainController
    ClientNetwork clientNetwork(&socket);

    Screen screen = Screen::LOGIN;

    //Login screen
    User user;
    LoginController loginCon(&user, &clientNetwork);
    LoginUI loginUI(&loginCon);
    

    //Lobby screen

    //Game screen


    switch (screen)
    {
    case Screen::LOGIN:
        loginUI.Run();
        break;

        // case Screen::LOBBY:

        //     break;

        // case Screen::GAME:

        //     break;

    default:
        logl("Hello");
        break;
    }

    return 0;
}