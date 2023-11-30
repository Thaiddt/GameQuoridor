#pragma once

#include <vector>
#include "Player.hpp"

class Board {
public:
    Board(int sizeX, int sizeY);
    Board();

    void AddPlayer(const Player& player);
    void MovePlayer(int playerIndex, int newX, int newY);

    const std::vector<Player>& getPlayers() const;

private:
    int boardSizeX;
    int boardSizeY;
    std::vector<Player> players;
};
