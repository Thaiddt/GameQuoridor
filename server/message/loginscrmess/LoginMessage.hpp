#pragma once

#include "MessageType.hpp"
#include <string>

struct LoginMessage {
    MessageType type;
    std::string username;
    std::string password;
};