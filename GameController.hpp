#pragma once
#include "Game.hpp"
#include "Player.hpp"
#include "Table.hpp"
#include <iostream>

class GameController {
private:
    Game ticTacToe;           // Obiectul jocului
    Player jucător1;         // Jucătorul 1
    Player jucător2;         // Jucătorul 2

public:
    // Constructor implicit
    GameController();

    // Constructor cu parametri
    GameController(const std::string& name1, const std::string& name2);

    // Constructor de copiere
    GameController(const GameController& other);

    // Operator de copiere
    GameController& operator=(const GameController& other);

    // Operator de comparație
    bool operator==(const GameController& other) const;

    // Operator de afișare
    friend std::ostream& operator<<(std::ostream& os, const GameController& controller);

    // Operator de citire
    friend std::istream& operator>>(std::istream& is, GameController& controller);

    // Funcția pentru a începe jocul
    void startGame();
};
