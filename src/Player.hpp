#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>

struct Player
{
    std::string name{};
    char symbol{'X'};

    void create_player();
};

#endif // PLAYER_HPP