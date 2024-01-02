#pragma once

#include "MessageType.hpp"

struct WallPlacementMessage {
    MessageType type;
    int playerID; // ID của người chơi đặt tường
    int wallX;    // Tọa độ X của tường trên bảng game
    int wallY;    // Tọa độ Y của tường trên bảng game
    // Các trường khác cần thiết
};