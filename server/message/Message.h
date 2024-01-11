#pragma once

#ifndef MESSAGE_H
#define MESSAGE_H

#include <SFML/Network.hpp>

struct SignInMess
{
    sf::Uint8 mType;
    std::string username;
    std::string password;
};

struct SignUpMess
{
    sf::Uint8 mType;
    std::string username;
    std::string password;
};

sf::Packet &operator<<(sf::Packet &packet, const SignInMess &data);
sf::Packet &operator>>(sf::Packet &packet, SignInMess &data);
sf::Packet &operator<<(sf::Packet &packet, const SignUpMess &data);
sf::Packet &operator>>(sf::Packet &packet, SignUpMess &data);

#endif