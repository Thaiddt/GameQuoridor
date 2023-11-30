#pragma once

#include <SFML/Graphics.hpp>
#include "Board.hpp"

class Game {
public:
    Game();

    void Run();

private:
    sf::RenderWindow window;
    Board board;

    void DrawBoard();
    void DrawPlayers();
};
