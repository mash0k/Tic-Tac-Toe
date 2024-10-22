#pragma once
#include <string>
#include <iostream>

class Playerabstract {
public:
    virtual ~Playerabstract() = default; // Destructor virtual

    virtual int readMove() const = 0; // Funcție virtuală pură
    virtual std::string getName() const = 0; // Funcție virtuală pură
};

class Player
{
private:
    std::string name;  

public:
    // Constructor implicit
    Player();

    // Constructor de copiere
    Player(const Player& other);

    // Constructor cu parametri
    Player(const std::string& playerName);

    // Operator de copiere
    Player& operator=(const Player& other);

    // Operator de comparație
    bool operator==(const Player& other) const;

    // Operator de afișare
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    // Operator de citire
    friend std::istream& operator>>(std::istream& is, Player& player);

    // Funcții adiționale
    int readMove() const;
    std::string getName() const;
};
