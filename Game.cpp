#include "Game.hpp"

// Constructor implicit
Game::Game() : gameOver(false), currentPlayer(Mark::X) {}

// Constructor de copiere
Game::Game(const Game& other)
    : board(other.board), gameOver(other.gameOver), currentPlayer(other.currentPlayer) {}

// Constructor cu parametri
Game::Game(const Table& board, bool gameOver, Mark currentPlayer)
    : board(board), gameOver(gameOver), currentPlayer(currentPlayer) {}

// Operator de copiere
Game& Game::operator=(const Game& other)
{
    if (this != &other)
    {
        board = other.board;
        gameOver = other.gameOver;
        currentPlayer = other.currentPlayer;
    }
    return *this;
}

// Operator de comparație
bool Game::operator==(const Game& other) const
{
    return board == other.board &&
           gameOver == other.gameOver &&
           currentPlayer == other.currentPlayer;
}

// Operator de afișare
std::ostream& operator<<(std::ostream& os, const Game& game)
{
    os << "Current Player: " << static_cast<int>(game.currentPlayer) << std::endl;
    os << "Game Over: " << game.gameOver << std::endl;
    os << game.board; // presupunând că există un operator de afișare pentru `Table`
    return os;
}

// Operator de citire
std::istream& operator>>(std::istream& is, Game& game)
{
    int currentPlayer;
    bool gameOver;
    is >> currentPlayer >> gameOver;
    game.currentPlayer = static_cast<Mark>(currentPlayer);
    game.gameOver = gameOver;
    is >> game.board; // presupunând că există un operator de citire pentru `Table`
    return is;
}

// Funcția de inițializare
void Game::initialize()
{
    gameOver = false;
    currentPlayer = Mark::X;
}

// Verificarea câștigătorului
bool Game::hasWinner() const
{
    // Verificarea rândurilor
    for (int i = 0; i < 3; ++i)
    {
        if (board.isCellL(i, 0)) // Dacă prima celulă este goală, continuă
            continue;

        // Verifică dacă toate cele trei celule din rândul `i` sunt egale
        if (board.getCell(i, 0) == board.getCell(i, 1) &&
            board.getCell(i, 1) == board.getCell(i, 2))
        {
            return true; // Câștigător pe rândul `i`
        }
    }

    // Verificarea coloanelor
    for (int j = 0; j < 3; ++j)
    {
        if (board.isCellL(0, j)) // Dacă prima celulă este goală, continuă
            continue;

        // Verifică dacă toate cele trei celule din coloana `j` sunt egale
        if (board.getCell(0, j) == board.getCell(1, j) &&
            board.getCell(1, j) == board.getCell(2, j))
        {
            return true; // Câștigător pe coloana `j`
        }
    }

    // Verificarea diagonalelor
    if (!board.isCellL(1, 1)) // Dacă centrul tablei nu este gol
    {
        // Diagonala principală (de la stânga sus la dreapta jos)
        if (board.getCell(0, 0) == board.getCell(1, 1) &&
            board.getCell(1, 1) == board.getCell(2, 2))
        {
            return true; // Câștigător pe diagonala principală
        }

        // Diagonala secundară (de la dreapta sus la stânga jos)
        if (board.getCell(0, 2) == board.getCell(1, 1) &&
            board.getCell(1, 1) == board.getCell(2, 0))
        {
            return true; // Câștigător pe diagonala secundară
        }
    }

    return false; // Nu există câștigător
}

// Verifică dacă jocul este remiză
bool Game::isDraw() const
{
    return board.isFull() && !hasWinner();
}

// Efectuează o mișcare
void Game::makeMove(int row, int col)
{
    if (!gameOver && board.isCellL(row, col))
    {
        board.updateCell(row, col, currentPlayer);
        if (hasWinner() || isDraw())
            gameOver = true;
        else
            currentPlayer = (currentPlayer == Mark::X) ? Mark::O : Mark::X;
    }
}

// Obține jucătorul curent
Mark Game::getCurrentPlayer() const
{
    return currentPlayer;
}

// Afișează starea jocului
void Game::display() const
{
    board.display();
};
