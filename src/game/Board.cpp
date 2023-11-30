#include "Board.hpp"

Board::Board(int sizeX, int sizeY) : boardSizeX(sizeX), boardSizeY(sizeY) {}

Board::Board() : boardSizeX(0), boardSizeY(0) {}

void Board::AddPlayer(const Player& player) {
    players.push_back(player);
}

void Board::MovePlayer(int playerIndex, int newX, int newY) {
    if (playerIndex >= 0 && playerIndex < players.size()) {
        players[playerIndex].Move(newX, newY);
    }
}

const std::vector<Player>& Board::getPlayers() const {
    return players;
}
