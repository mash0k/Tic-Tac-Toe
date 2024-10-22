#pragma once
#include "Table.hpp"
#include <iostream>

class Game1 {
public:
    virtual ~Game1() = default; // Destructor virtual

    virtual void initialize() = 0; 
    virtual bool hasWinner() const = 0; 
    virtual void makeMove(int row, int col) = 0; 
    virtual void display() const = 0; 
};

class Game
{
private:
    Table board;              // Tabla de joc
    bool gameOver;           // Indică dacă jocul s-a terminat
    Mark currentPlayer;      // Jucătorul curent

public:
    // Constructor implicit
    Game();

    // Constructor de copiere
    Game(const Game& other);

    // Constructor cu parametri
    Game(const Table& board, bool gameOver, Mark currentPlayer);

    // Operator de copiere
    Game& operator=(const Game& other);

    // Operator de comparație
    bool operator==(const Game& other) const;

    // Operator de afișare
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

    // Operator de citire
    friend std::istream& operator>>(std::istream& is, Game& game);

    // Funcții suplimentare
    void initialize();
    bool hasWinner() const;
    bool isDraw() const;
    void makeMove(int row, int col);
    Mark getCurrentPlayer() const;
    void display() const;
};

