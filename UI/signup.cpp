#include <iostream>
#include<vector>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

const double W = 1080;

RenderWindow window(VideoMode(W, W), "Quoridor", Style::Default);
Font inika, jasque;
Texture fieldcfpassword, background, fieldusername, fieldpassword, buttonsignup, buttonback;


struct signUp_box{
    Sprite field_userName;
    Sprite field_passWord;
    Sprite field_cfpassWord;
    Sprite button_signUp;
    Sprite back;
    Text text_username;
    Text text_password;
    Text text_cfpassword;
    Text text_signUp;
    Text text_back;
    Text game_name;
};


// Functions display
void drawSignup(signUp_box box);
void setSignup(signUp_box& box);
void texturesAndFonts();
int main(){
    texturesAndFonts();
    signUp_box box;
    setSignup(box);
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
        drawSignup(box);
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
    fieldcfpassword.loadFromFile("Assert/Signin/username.png");
    buttonsignup.loadFromFile("Assert/Signin/signup.png");
    buttonback.loadFromFile("Assert/Signin/back.png");
}
void drawSignup(signUp_box box){
    window.draw(box.field_userName);
    window.draw(box.field_passWord);
    window.draw(box.field_cfpassWord);
    window.draw(box.button_signUp);
    window.draw(box.text_username);
    window.draw(box.text_password);
    window.draw(box.text_cfpassword);
    window.draw(box.text_signUp);
    window.draw(box.back);
    window.draw(box.text_back);
    window.draw(box.game_name);
}
void setSignup(signUp_box& box){
    box.field_userName.setTexture(fieldusername);
    box.field_passWord.setTexture(fieldpassword);
    box.field_cfpassWord.setTexture(fieldcfpassword);
    box.back.setTexture(buttonback);
    // box.button_signIn.setTexture(buttonsignin);
    box.button_signUp.setTexture(buttonsignup);

    box.text_username.setFont(inika);
    box.text_password.setFont(inika);
    box.text_cfpassword.setFont(inika);
    box.text_signUp.setFont(inika);
    box.game_name.setFont(jasque);
    box.text_back.setFont(inika);

    box.text_username.setString("Username");
    box.text_password.setString("Password");
    box.text_cfpassword.setString("Confirm Password");
    box.text_signUp.setString("Sign Up");
    box.game_name.setString("Quoridor");
    box.text_back.setString("Back");
    box.text_username.setCharacterSize(30);
    box.text_password.setCharacterSize(30);
    box.text_cfpassword.setCharacterSize(30);
    // box.text_signIn.setCharacterSize(20);
    box.text_signUp.setCharacterSize(20);
    box.text_back.setCharacterSize(20);
    box.game_name.setCharacterSize(100);
    box.text_username.setFillColor(Color::Black);
    box.text_password.setFillColor(Color::Black);
    box.text_cfpassword.setFillColor(Color::Black);
    // box.text_signIn.setFillColor(Color::Black);
    box.text_signUp.setFillColor(Color::Black);
    box.game_name.setFillColor(Color::Red);
    box.text_username.setPosition(300, 330);
    box.text_password.setPosition(300, 480);
    box.text_cfpassword.setPosition(200, 630);
    box.game_name.setPosition(450, 100);
    box.field_userName.setPosition(500, 300);
    box.field_passWord.setPosition(500, 450);
    box.field_cfpassWord.setPosition(500, 600);
    box.back.setPosition(50, 900); 
    // box.button_signIn.setPosition(500, 600);
    box.button_signUp.setPosition(740, 720);
    // box.text_signIn.setPosition(box.button_signIn.getPosition().x+70, box.button_signIn.getPosition().y+15);
    box.text_signUp.setPosition(box.button_signUp.getPosition().x+49, box.button_signUp.getPosition().y+15);
    box.text_back.setPosition(box.back.getPosition().x+30, box.back.getPosition().y+20);
}