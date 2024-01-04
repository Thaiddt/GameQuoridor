// ScreenManager.cpp
#include "UIManager.hpp"

UIManager::UIManager() : currentScreen(Screen::None) {}

sf::RenderWindow& UIManager::GetLoginScreen() {
    return loginScreen;
}

sf::RenderWindow& UIManager::GetLobbyScreen() {
    return lobbyScreen;
}

sf::RenderWindow& UIManager::GetGameScreen() {
    return gameScreen;
}

void UIManager::ShowLoginScreen() {
    HideAllScreens();
    loginScreen.create(sf::VideoMode(800, 600), "Login Screen");
    currentScreen = Screen::Login;
}

void UIManager::ShowLobbyScreen() {
    HideAllScreens();
    lobbyScreen.create(sf::VideoMode(800, 600), "Lobby Screen");
    currentScreen = Screen::Lobby;
}

void UIManager::ShowGameScreen() {
    HideAllScreens();
    gameScreen.create(sf::VideoMode(800, 600), "Game Screen");
    currentScreen = Screen::Game;
}

void UIManager::HideAllScreens() {
    loginScreen.close();
    lobbyScreen.close();
    gameScreen.close();
    currentScreen = Screen::None;
}

Screen UIManager::GetCurrentScreen() const {
    return currentScreen;
}
