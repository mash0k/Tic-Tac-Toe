#pragma once
#include <string>
#include <iostream>

class Player
{
private:
    std::string name;  

public:
    Player(const std::string& playerName);

    int readMove() const;

    std::string getName() const;
};
