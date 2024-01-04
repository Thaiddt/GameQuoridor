#include "GameManager.hpp"

GameManager::GameManager(){

}

void UIControll(){
    UIManager UIManager;

    while (UIManager.GetCurrentScreen() != Screen::None) {
        sf::Event event;
        while (UIManager.GetCurrentScreen() != Screen::None && 
               UIManager.GetCurrentScreen() == Screen::Login && UIManager.GetLoginScreen().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                UIManager.HideAllScreens();
            }
        }

        while (UIManager.GetCurrentScreen() != Screen::None && 
               UIManager.GetCurrentScreen() == Screen::Lobby && UIManager.GetLobbyScreen().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                UIManager.HideAllScreens();
            }
        }

        while (UIManager.GetCurrentScreen() != Screen::None && 
               UIManager.GetCurrentScreen() == Screen::Game && UIManager.GetGameScreen().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                UIManager.HideAllScreens();
            }
        }

        // Thêm logic xử lý và vẽ của từng màn hình ở đây
        // ...

        // Hiển thị cửa sổ tương ứng với màn hình hiện tại
        if (UIManager.GetCurrentScreen() == Screen::Login) {
            UIManager.GetLoginScreen().display();
        } else if (UIManager.GetCurrentScreen() == Screen::Lobby) {
            UIManager.GetLobbyScreen().display();
        } else if (UIManager.GetCurrentScreen() == Screen::Game) {
            UIManager.GetGameScreen().display();
        }
    }
}