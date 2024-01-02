#pragma once

#include "MessageType.hpp"
#include <string>

struct RegisterMessage {
    MessageType type;
    std::string username;
    std::string password;
};