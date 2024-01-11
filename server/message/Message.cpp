#include "Message.h"

sf::Packet &operator<<(sf::Packet &packet, const SignInMess &data)
{
    return packet << data.mType << data.username << data.password;
}

sf::Packet &operator>>(sf::Packet &packet, SignInMess &data)
{
    return packet >> data.mType >> data.username >> data.password;
}

sf::Packet &operator<<(sf::Packet &packet, const SignUpMess &data)
{
    return packet << data.mType << data.username << data.password;
}

sf::Packet &operator>>(sf::Packet &packet, SignUpMess &data)
{
    return packet >> data.mType >> data.username >> data.password;
}