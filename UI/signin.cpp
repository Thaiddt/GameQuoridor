#include <iostream>
#include<vector>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

const double W = 1080;

RenderWindow window(VideoMode(W, W), "Quoridor", Style::Default);
Font inika, jasque;
Texture background, fieldusername, fieldpassword, buttonsignin, buttonsignup;


struct signIn_box{
    Sprite field_userName;
    Sprite field_passWord;
    Sprite button_signIn;
    Sprite button_signUp;
    Text text_username;
    Text text_password;
    Text text_signIn;
    Text text_signUp;
    Text game_name;
};


// Functions display
void drawSignin(signIn_box box);
void setSignin(signIn_box& box);
void texturesAndFonts();
int main(){
    texturesAndFonts();
    signIn_box box;
    setSignin(box);
    Sprite bbackground;
    bbackground.setTexture(background);
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(bbackground);
        drawSignin(box);
        window.display();
    }
    return 0;
}
// Excute fuctions displ
void texturesAndFonts(){
    inika.loadFromFile("Font/Inika-Regular.ttf");
    jasque.loadFromFile("Font/Jasques.ttf");
    background.loadFromFile("Assert/Signin/background.png");
    fieldusername.loadFromFile("Assert/Signin/username.png");
    fieldpassword.loadFromFile("Assert/Signin/username.png");
    buttonsignin.loadFromFile("Assert/Signin/signin.png");
    buttonsignup.loadFromFile("Assert/Signin/signup.png");
}
void drawSignin(signIn_box box){
    window.draw(box.field_userName);
    window.draw(box.field_passWord);
    window.draw(box.button_signIn);
    window.draw(box.button_signUp);
    window.draw(box.text_username);
    window.draw(box.text_password);
    window.draw(box.text_signIn);
    window.draw(box.text_signUp);
    window.draw(box.game_name);
}
void setSignin(signIn_box& box){
    box.field_userName.setTexture(fieldusername);
    box.field_passWord.setTexture(fieldpassword);
    box.button_signIn.setTexture(buttonsignin);
    box.button_signUp.setTexture(buttonsignup);
    box.text_username.setFont(inika);
    box.text_password.setFont(inika);
    box.text_signIn.setFont(inika);
    box.text_signUp.setFont(inika);
    box.game_name.setFont(jasque);
    box.text_username.setString("Username");
    box.text_password.setString("Password");
    box.text_signIn.setString("Sign In");
    box.text_signUp.setString("Sign Up");
    box.game_name.setString("Quoridor");
    box.text_username.setCharacterSize(30);
    box.text_password.setCharacterSize(30);
    box.text_signIn.setCharacterSize(20);
    box.text_signUp.setCharacterSize(20);
    box.game_name.setCharacterSize(100);
    box.text_username.setFillColor(Color::Black);
    box.text_password.setFillColor(Color::Black);
    box.text_signIn.setFillColor(Color::Black);
    box.text_signUp.setFillColor(Color::Black);
    box.game_name.setFillColor(Color::Red);
    box.text_username.setPosition(300, 330);
    box.text_password.setPosition(300, 480);
    box.game_name.setPosition(450, 100);
    box.field_userName.setPosition(500, 300);
    box.field_passWord.setPosition(500, 450);
    box.button_signIn.setPosition(500, 600);
    box.button_signUp.setPosition(740, 600);
    box.text_signIn.setPosition(box.button_signIn.getPosition().x+70, box.button_signIn.getPosition().y+15);
    box.text_signUp.setPosition(box.button_signUp.getPosition().x+49, box.button_signUp.getPosition().y+15);
}