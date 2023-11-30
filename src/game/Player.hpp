#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(int startX, int startY, sf::Color color);

    void Move(int newX, int newY);

    sf::Vector2i getPosition() const;
    sf::Color getColor() const;

private:
    sf::Vector2i position;
    sf::Color playerColor;
};
