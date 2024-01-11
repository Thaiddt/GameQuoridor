#pragma once
#include "./../controller/LoginController.h"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

const double W = 1080;

struct signIn_box
{
    Sprite bbackground;
    Sprite field_userName;
    Sprite field_passWord;
    Sprite button_signIn;
    Sprite button_signUp;
    Sprite userSprite;
    Sprite passSprite;

    Text text_username;
    Text text_password;
    Text text_signIn;
    Text text_signUp;
    Text game_name;

    Font inika;
    Font jasque;

    Texture background;
    Texture fieldusername;
    Texture fieldpassword;
    Texture buttonsignin;
    Texture buttonsignup;

    RenderTexture userTexture;
    RenderTexture passTexture;

    // String check username and password
    string currentUsername = "";
    string currentPassword = "";
    string displayedPassword;

    bool isTextUser = false;
    bool isTextPass = false;
    bool isTextCPass = false;
};

class LoginUI
{
    LoginController *loginController;

public:
    LoginUI(LoginController *LoginController);
    void IniSignInScreen(signIn_box *boxSignIn);
    void Run();
};