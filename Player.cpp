#include "Player.hpp"

// Constructor implicit
Player::Player() : name("Unnamed") {}

// Constructor de copiere
Player::Player(const Player& other) : name(other.name) {}

// Constructor cu parametri
Player::Player(const std::string& playerName) : name(playerName) {}

// Operator de copiere
Player& Player::operator=(const Player& other)
{
    if (this != &other)
    {
        name = other.name;
    }
    return *this;
}

// Operator de comparație
bool Player::operator==(const Player& other) const
{
    return name == other.name;
}

// Operator de afișare
std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << "Player Name: " << player.name;
    return os;
}

// Operator de citire
std::istream& operator>>(std::istream& is, Player& player)
{
    std::cout << "Enter player name: ";
    is >> player.name;
    return is;
}

// Funcție pentru citirea unei mișcări
int Player::readMove() const
{
    int move;
    std::cout << name << ", introdu rândul și coloana (1-3): ";
    std::cin >> move;
    return move - 1; // Convertim la index 0-based
}

// Returnează numele jucătorului
std::string Player::getName() const
{
    return name;
}
