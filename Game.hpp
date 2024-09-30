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
    Game()
    {
        // Initialize the game
        initialize();
    }

    void initialize()
    {
        // Set the initial state of the game (empty board, player X starts)
        // board.initialize();
        gameOver = false;
        currentPlayer = Mark::X;
    }

    bool hasWinner() const
    {
       // Check rows for a winner
    for (int i = 0; i < 3; ++i)
    {
        if (board.isCellL(i, 0))
            continue;

        if (board.getCell(i, 0) == board.getCell(i, 1) &&
            board.getCell(i, 1) == board.getCell(i, 2))
        {
            return true; // Row i is a winning row
        }
    }

    // Check columns for a winner
    for (int j = 0; j < 3; ++j)
    {
        if (board.isCellL(0, j))
            continue;

        if (board.getCell(0, j) == board.getCell(1, j) &&
            board.getCell(1, j) == board.getCell(2, j))
        {
            return true; // Column j is a winning column
        }
    }

    // Check diagonals for a winner
    if (!board.isCellL(1, 1))
    {
        if ((board.getCell(0, 0) == board.getCell(1, 1) &&
             board.getCell(1, 1) == board.getCell(2, 2)) ||
            (board.getCell(0, 2) == board.getCell(1, 1) &&
             board.getCell(1, 1) == board.getCell(2, 0)))
        {
            return true; // Diagonals are winning
        }
    }

    return false; // No winner found
        // Check rows, columns, and diagonals for a winner
        // Return true if there is a winner, otherwise false
        // (You need to implement this logic)
    }

    bool isDraw() const
    {
        // Check if the board is full (no more empty cells) and there is no winner
        return board.isFull() && !hasWinner();
    }

    void makeMove(int row, int col)
    {
        // Check if the move is valid and update the board
        if (!gameOver && board.isCellL(row, col))
        {
            board.updateCell(row, col, currentPlayer);
            if (hasWinner() || isDraw())
                gameOver = true;
            else
                currentPlayer = (currentPlayer == Mark::X) ? Mark::O : Mark::X;
        }
    }

    Mark getCurrentPlayer() const
    {
        return currentPlayer;
    }

    void display() const
    {
        // Display the current state of the board
        board.display();
    }
};
