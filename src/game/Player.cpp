#include "Player.hpp"

Player::Player(int startX, int startY, sf::Color color)
    : position(startX, startY), playerColor(color) {}

void Player::Move(int newX, int newY) {
    position.x = newX;
    position.y = newY;
}

sf::Vector2i Player::getPosition() const {
    return position;
}

sf::Color Player::getColor() const {
    return playerColor;
}
