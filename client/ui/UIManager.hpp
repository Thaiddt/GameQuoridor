#pragma once
#include <SFML/Graphics.hpp>

enum class Screen {
    None,
    Login,
    Lobby,
    Game
};

class UIManager {
public:
    UIManager();
    sf::RenderWindow& GetLoginScreen();
    sf::RenderWindow& GetLobbyScreen();
    sf::RenderWindow& GetGameScreen();

    void ShowLoginScreen();
    void ShowLobbyScreen();
    void ShowGameScreen();
    void HideAllScreens();

    Screen GetCurrentScreen() const;

private:
    sf::RenderWindow loginScreen;
    sf::RenderWindow lobbyScreen;
    sf::RenderWindow gameScreen;
    Screen currentScreen;
};
