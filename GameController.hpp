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
    GameController(const std::string& name1, const std::string& name2)
        : jucător1(name1), jucător2(name2)
    {
        // Inițializează jocul și setează numele jucătorilor
        ticTacToe.initialize();
    }

    void startGame()
    {
        std::cout << "Bun venit la Tic Tac Toe, " << jucător1.getName() << " și " << jucător2.getName() << "!\n";

        while (!ticTacToe.hasWinner() && !ticTacToe.isDraw())
        {
            ticTacToe.display();
            int row = jucător1.readMove();
            int col = jucător1.readMove();
            ticTacToe.makeMove(row, col);
        }

        ticTacToe.display();
        if (ticTacToe.hasWinner())
            std::cout << "Felicitări, " << (ticTacToe.getCurrentPlayer() == Mark::X ? jucător2.getName() :  jucător1.getName()) << "! Ai câștigat!\n";
        else
            std::cout << "Remiză! Jocul s-a încheiat.\n";
    }
};