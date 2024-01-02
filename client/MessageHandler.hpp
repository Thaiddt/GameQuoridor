// Trong MessageHandler.hpp
#pragma once

#include <string>
#include "message/MessageType.hpp"
#include "message/gamescrmess/WallPlacementMessage.hpp"
#include "message/lobbyscrmess/LogoutMessage.hpp"
#include "message/lobbyscrmess/MatchLogRequestMessage.hpp"
#include "message/lobbyscrmess/MatchPlayerRequestMessage.hpp"
#include "message/lobbyscrmess/UserInfoRequestMessage.hpp"
#include "message/loginscrmess/LoginMessage.hpp"
#include "message/loginscrmess/RegisterMessage.hpp"

class MessageHandler {
public:
    static std::string serializeMessage(const MessageType& messageType, const std::string& jsonData);
    static std::pair<MessageType, std::string> deserializeMessage(const std::string& serializedMessage);

private:
    // Hàm serialize và deserialize cho các loại thông điệp
    static std::string serializeLoginMessage(const LoginMessage& message);
    static LoginMessage deserializeLoginMessage(const std::string& jsonData);

    static std::string serializeRegisterMessage(const RegisterMessage& message);
    static RegisterMessage deserializeRegisterMessage(const std::string& jsonData);

    static std::string serializeUserInfoRequestMessage(const UserInfoRequestMessage& message);
    static UserInfoRequestMessage deserializeUserInfoRequestMessage(const std::string& jsonData);

    static std::string serializeMatchPlayerRequestMessage(const MatchPlayerRequestMessage& message);
    static MatchPlayerRequestMessage deserializeMatchPlayerRequestMessage(const std::string& jsonData);

    static std::string serializeMatchLogRequestMessage(const MatchLogRequestMessage& message);
    static MatchLogRequestMessage deserializeMatchLogRequestMessage(const std::string& jsonData);

    static std::string serializeLogoutMessage(const LogoutMessage& message);
    static LogoutMessage deserializeLogoutMessage(const std::string& jsonData);

    static std::string serializeWallPlacementMessage(const WallPlacementMessage& message);
    static WallPlacementMessage deserializeWallPlacementMessage(const std::string& jsonData);
};
