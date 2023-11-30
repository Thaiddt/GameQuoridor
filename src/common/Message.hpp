#pragma once

enum class MessageType {
    Move,
    GameStateUpdate,
    PlayerConnection,
};

struct Message {
    MessageType type;
};
