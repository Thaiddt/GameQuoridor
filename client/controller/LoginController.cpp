#include "LoginController.h"

LoginController::LoginController(User *user, ClientNetwork *clientNetwork)
{
    LoginController::user = user;
    LoginController::clientNetwork = clientNetwork;
}

void LoginController::signIn(string username, string password){
    SignInMess signInMess;
    signInMess.username = username;
    signInMess.password = password;
    Packet packet;
    packet << signInMess;
    LoginController::clientNetwork->sendMessToServer(packet);
    // packet.clear();
    // LoginController::clientNetwork->recvMessToServer(packet);
    // Uint8 recvPac;
    // packet >> recvPac;
    // logl(recvPac);
}

void LoginController::signUp(string username, string password){
    // SignUpMess signUpMess;
    // signUpMess.username = username;
    // signUpMess.password = password;
    // Packet packet;
    // packet << signUpMess;
    // LoginController::clientNetwork->sendMessToServer(packet);
}