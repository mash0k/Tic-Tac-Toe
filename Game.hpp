#pragma once
#include "Table.hpp"
#include <iostream>

class Game
{
private:
    Table board;
    bool gameOver;
    Mark currentPlayer;

public:
    Game();
    void initialize();
    bool hasWinner() const;
    bool isDraw() const;
    void makeMove(int row, int col);
    Mark getCurrentPlayer() const;
    void display() const;
};
