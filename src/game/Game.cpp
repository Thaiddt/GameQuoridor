#include "Game.hpp"

Game::Game() : window(sf::VideoMode(800, 600), "Quoridor Game") {
    board = Board(9, 9);
    Player player1(0, 0, sf::Color::Blue);
    Player player2(8, 8, sf::Color::Red);
    board.AddPlayer(player1);
    board.AddPlayer(player2);
}

void Game::Run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        // Draw the board
        DrawBoard();

        // Draw the players
        DrawPlayers();

        window.display();
    }
}

void Game::DrawBoard() {
    // Draw the grid lines and other board elements
    // ...

    // For simplicity, let's draw a simple grid here
    sf::RectangleShape cell(sf::Vector2f(50, 50));
    cell.setOutlineThickness(1.0f);
    cell.setOutlineColor(sf::Color::Black);

    for (int x = 0; x < 9; ++x) {
        for (int y = 0; y < 9; ++y) {
            cell.setPosition(x * 50, y * 50);
            window.draw(cell);
        }
    }
}

void Game::DrawPlayers() {
    // Draw each player on the board
    const auto& players = board.getPlayers();

    for (const auto& player : players) {
        sf::CircleShape playerShape(25);
        playerShape.setFillColor(player.getColor());
        playerShape.setPosition(player.getPosition().x * 50, player.getPosition().y * 50);
        window.draw(playerShape);
    }
}
