#include "GameController.hpp"

// Constructor implicit
GameController::GameController() 
    : jucător1("Jucător 1"), jucător2("Jucător 2") // nume default
{
    // Inițializează jocul
    ticTacToe.initialize();
}

// Constructor cu parametri
GameController::GameController(const std::string& name1, const std::string& name2)
    : jucător1(name1), jucător2(name2)
{
    // Inițializează jocul
    ticTacToe.initialize();
}

// Constructor de copiere
GameController::GameController(const GameController& other)
    : ticTacToe(other.ticTacToe), jucător1(other.jucător1), jucător2(other.jucător2) {}

// Operator de copiere
GameController& GameController::operator=(const GameController& other)
{
    if (this != &other)
    {
        ticTacToe = other.ticTacToe;
        jucător1 = other.jucător1;
        jucător2 = other.jucător2;
    }
    return *this;
}

// Operator de comparație
bool GameController::operator==(const GameController& other) const
{
    return ticTacToe == other.ticTacToe &&
           jucător1.getName() == other.jucător1.getName() &&
           jucător2.getName() == other.jucător2.getName();
}

// Operator de afișare
std::ostream& operator<<(std::ostream& os, const GameController& controller)
{
    os << "GameController:\n";
    os << "Player 1: " << controller.jucător1.getName() << "\n";
    os << "Player 2: " << controller.jucător2.getName() << "\n";
    os << controller.ticTacToe; // Afișează jocul
    return os;
}

// Operator de citire
std::istream& operator>>(std::istream& is, GameController& controller)
{
    std::string name1, name2;
    is >> name1 >> name2;
    controller.jucător1 = Player(name1);
    controller.jucător2 = Player(name2);
    is >> controller.ticTacToe; // presupunând că există un operator de citire pentru `Game`
    return is;
}

// Funcția de start a jocului
void GameController::startGame()
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