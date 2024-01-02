#pragma once

enum class MessageType {
    // Common Messages
    UNKNOWN,
    
    // LoginScreen Messages
    LOGIN,
    REGISTER,

    // LobbyScreen Messages
    USER_INFO_REQUEST,
    MATCH_PLAYER_REQUEST,
    MATCH_LOG_REQUEST,
    LOGOUT,

    // GameScreen Messages
    WALL_PLACEMENT,
};