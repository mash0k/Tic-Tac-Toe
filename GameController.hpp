#pragma once
#include "Game.hpp"
#include "Player.hpp"
#include "Table.hpp"
#include <iostream>

class GameController
{
private:
    Game ticTacToe;
    Player jucător1;
    Player jucător2;

public:
    GameController(const std::string& name1, const std::string& name2);
    void startGame();
};