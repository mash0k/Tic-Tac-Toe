#pragma once
#include <string>
#include <iostream>

class Player
{
private:
    std::string name;

public:
    Player(const std::string& playerName) : name(playerName) {}

    int readMove() const
    {
        int move;
        std::cout << name << ", introdu rândul și coloana (1-3): ";
        std::cin >> move;
        return move - 1; // Convertim la index 0-based
    }

    std::string getName() const
    {
        return name;
    }
};