#pragma once
#include "./../model/User.h"
#include "./../network/ClientNetwork.h"
#include "./../message/Message.h"

class LoginController
{
    User *user;
    ClientNetwork *clientNetwork;

public:
    LoginController(User *user, ClientNetwork *clientNetwork);
    void signIn(string username, string password);
    void signUp(string username, string password);
};