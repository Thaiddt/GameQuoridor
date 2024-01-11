#include "LoginUI.h"

LoginUI::LoginUI(LoginController *loginController){
    LoginUI::loginController = loginController;
}

void DrawSignInScreen(RenderWindow *window, signIn_box *boxSignin)
{
    window->draw(boxSignin->bbackground);
    window->draw(boxSignin->field_userName);
    window->draw(boxSignin->field_passWord);
    window->draw(boxSignin->button_signIn);
    window->draw(boxSignin->button_signUp);
    window->draw(boxSignin->text_username);
    window->draw(boxSignin->text_password);
    window->draw(boxSignin->text_signIn);
    window->draw(boxSignin->text_signUp);
    window->draw(boxSignin->game_name);
    window->draw(boxSignin->userSprite);
    window->draw(boxSignin->passSprite);
}

// void LoginUI::DrawSignUpScreen(RenderWindow *window, signIn_box *boxSignUp){

// }

void LoginUI::IniSignInScreen(signIn_box *boxSignIn){
    boxSignIn->inika.loadFromFile("fonts/Inika-Regular.ttf");
    boxSignIn->jasque.loadFromFile("fonts/Jasques.ttf");
    boxSignIn->background.loadFromFile("assets/background.png");
    boxSignIn->fieldusername.loadFromFile("assets/username.png");
    boxSignIn->fieldpassword.loadFromFile("assets/username.png");
    boxSignIn->buttonsignin.loadFromFile("assets/signin.png");
    boxSignIn->buttonsignup.loadFromFile("assets/signup.png");

    boxSignIn->bbackground.setTexture(boxSignIn->background);
    boxSignIn->field_userName.setTexture(boxSignIn->fieldusername);
    boxSignIn->field_passWord.setTexture(boxSignIn->fieldpassword);
    boxSignIn->button_signIn.setTexture(boxSignIn->buttonsignin);
    boxSignIn->button_signUp.setTexture(boxSignIn->buttonsignup);

    boxSignIn->text_username.setFont(boxSignIn->inika);
    boxSignIn->text_password.setFont(boxSignIn->inika);
    boxSignIn->text_signIn.setFont(boxSignIn->inika);
    boxSignIn->text_signUp.setFont(boxSignIn->inika);
    boxSignIn->game_name.setFont(boxSignIn->jasque);
    boxSignIn->text_username.setString("Username");
    boxSignIn->text_password.setString("Password");
    boxSignIn->text_signIn.setString("Sign In");
    boxSignIn->text_signUp.setString("Sign Up");
    boxSignIn->game_name.setString("Quoridor");
    boxSignIn->text_username.setCharacterSize(30);
    boxSignIn->text_password.setCharacterSize(30);
    boxSignIn->text_signIn.setCharacterSize(20);
    boxSignIn->text_signUp.setCharacterSize(20);
    boxSignIn->game_name.setCharacterSize(100);
    boxSignIn->text_username.setFillColor(Color::Black);
    boxSignIn->text_password.setFillColor(Color::Black);
    boxSignIn->text_signIn.setFillColor(Color::Black);
    boxSignIn->text_signUp.setFillColor(Color::Black);
    boxSignIn->game_name.setFillColor(Color::Red);
    boxSignIn->text_username.setPosition(300, 330);
    boxSignIn->text_password.setPosition(300, 480);
    boxSignIn->game_name.setPosition(450, 100);
    boxSignIn->field_userName.setPosition(500, 300);
    boxSignIn->field_passWord.setPosition(500, 450);
    boxSignIn->button_signIn.setPosition(500, 600);
    boxSignIn->button_signUp.setPosition(740, 600);
    boxSignIn->text_signIn.setPosition(boxSignIn->button_signIn.getPosition().x + 70, boxSignIn->button_signIn.getPosition().y + 15);
    boxSignIn->text_signUp.setPosition(boxSignIn->button_signUp.getPosition().x + 49, boxSignIn->button_signUp.getPosition().y + 15);
    boxSignIn->userTexture.create(boxSignIn->fieldusername.getSize().x, boxSignIn->fieldusername.getSize().y);
    boxSignIn->userTexture.clear(sf::Color::Transparent);
    boxSignIn->passTexture.create(boxSignIn->fieldpassword.getSize().x, boxSignIn->fieldpassword.getSize().y);
    boxSignIn->passTexture.clear(sf::Color::Transparent);
}

void LoginUI::Run()
{
    //Initialization
    RenderWindow window(VideoMode(W, W), "Quoridor", Style::Default);
    signIn_box boxSignIn;

    bool isSignInS = true;
    // Set sign in
    LoginUI::IniSignInScreen(&boxSignIn);


    // Main loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            //Kiem tra click chuot trai
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                logl("Clicked");
                Vector2i mousePosition = sf::Mouse::getPosition(window);
                FloatRect spriteBoundFU = boxSignIn.field_userName.getGlobalBounds();
                FloatRect spriteBoundFP = boxSignIn.field_passWord.getGlobalBounds();
                FloatRect spriteBoundSIB = boxSignIn.button_signIn.getGlobalBounds();
                FloatRect spriteBoundSUB = boxSignIn.button_signUp.getGlobalBounds();

                if (spriteBoundFU.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                {
                    logl("User found");
                    boxSignIn.isTextUser = true;
                }else boxSignIn.isTextUser = false;

                if (spriteBoundFP.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                {
                    logl("Pass found");
                   boxSignIn.isTextPass = true;
                }else boxSignIn.isTextPass = false;

                if (spriteBoundSIB.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                {
                    LoginUI::loginController->signIn(boxSignIn.currentUsername, boxSignIn.currentPassword);
                }

                if (spriteBoundSUB.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                {

                }
            }
            
            //Kiem tra nhan ky hieu ban phim
            if (event.type == Event::TextEntered)
            {
                logl("Is text");
                if (event.text.unicode >= 32 && event.text.unicode < 128 && boxSignIn.isTextUser)
                {
                    boxSignIn.currentUsername += static_cast<char>(event.text.unicode);

                    boxSignIn.userTexture.clear(sf::Color::Transparent);
                    Text text(boxSignIn.currentUsername, boxSignIn.inika, 20);
                    text.setFillColor(Color::Black);
                    boxSignIn.userTexture.draw(text);
                    boxSignIn.userTexture.display();
                    boxSignIn.userSprite.setTexture(boxSignIn.userTexture.getTexture());
                    boxSignIn.userSprite.setPosition(boxSignIn.field_userName.getPosition().x + 20, boxSignIn.field_userName.getPosition().y + 30);
                }

                if (event.text.unicode >= 32 && event.text.unicode < 128 &&boxSignIn.isTextPass)
                {
                    
                    boxSignIn.currentPassword += static_cast<char>(event.text.unicode);
                    boxSignIn.displayedPassword.assign(boxSignIn.currentPassword.length(), '*');
                    
                    boxSignIn.passTexture.clear(sf::Color::Transparent);
                    Text text(boxSignIn.displayedPassword, boxSignIn.inika, 20);
                    text.setFillColor(Color::Black);
                    boxSignIn.passTexture.draw(text);
                    boxSignIn.passTexture.display();
                    boxSignIn.passSprite.setTexture(boxSignIn.passTexture.getTexture());
                    boxSignIn.passSprite.setPosition(boxSignIn.field_passWord.getPosition().x + 20, boxSignIn.field_passWord.getPosition().y + 35);
                }
            }

            //Kiem tra xoa
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::BackSpace)
                {
                    if (!boxSignIn.currentUsername.empty() && boxSignIn.isTextUser)
                    {
                        logl("In");
                        boxSignIn.currentUsername.pop_back();

                        boxSignIn.userTexture.clear(sf::Color::Transparent);
                        Text text(boxSignIn.currentUsername, boxSignIn.inika, 20);
                        text.setFillColor(Color::Black);
                        boxSignIn.userTexture.draw(text);
                        boxSignIn.userTexture.display();
                        boxSignIn.userSprite.setTexture(boxSignIn.userTexture.getTexture());
                        boxSignIn.userSprite.setPosition(boxSignIn.field_userName.getPosition().x + 20, boxSignIn.field_userName.getPosition().y + 30);
                    }

                    if (!boxSignIn.currentPassword.empty() &&boxSignIn.isTextPass)
                    {
                        logl("In");
                        boxSignIn.currentPassword.pop_back(); 
                        boxSignIn.displayedPassword.assign(boxSignIn.currentPassword.length(), '*');
                        
                        boxSignIn.passTexture.clear(sf::Color::Transparent);
                        Text text(boxSignIn.displayedPassword, boxSignIn.inika, 20);
                        text.setFillColor(Color::Black);
                        boxSignIn.passTexture.draw(text);
                        boxSignIn.passTexture.display();
                        boxSignIn.passSprite.setTexture(boxSignIn.passTexture.getTexture());
                        boxSignIn.passSprite.setPosition(boxSignIn.field_passWord.getPosition().x + 20, boxSignIn.field_passWord.getPosition().y + 35);
                    }
                }
            }
        }

        //Draw
        window.clear();
        if (isSignInS)
        {
            DrawSignInScreen(&window, &boxSignIn);
        }
        // DrawSignUpScreen(&window, &boxSignUp);
        window.display();
    }
}
