#pragma once

#include <SFML/Graphics.hpp>
#include "LoginScreen.hpp"
#include "LobbyScreen.hpp"
#include "GameScreen.hpp"

class UIManager {
public:
    UIManager();

    void initialize();
    void update();
    void draw();

    // Các phương thức khác cần thiết

private:
    sf::RenderWindow window;
    LoginScreen loginScreen;
    LobbyScreen lobbyScreen;
    GameScreen gameScreen;

    // Các trạng thái và biến khác cho quản lý giao diện người dùng
};