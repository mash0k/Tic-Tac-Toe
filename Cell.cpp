#include "Cell.hpp"

// Constructor implicit
Cell::Cell() : state(Mark::Gol) {}

// Constructor de copiere
Cell::Cell(const Cell& other) : state(other.state) {}

// Constructor cu parametri
Cell::Cell(Mark state) : state(state) {}

// Operator de copiere
Cell& Cell::operator=(const Cell& other)
{
    if (this != &other)
    {
        state = other.state;
    }
    return *this;
}

// Operator de comparație
bool Cell::operator==(const Cell& other) const
{
    return state == other.state;
}

// Operator de afișare
std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
    os << static_cast<int>(cell.state);
    return os;
}

// Operator de citire
std::istream& operator>>(std::istream& is, Cell& cell)
{
    int markValue;
    is >> markValue;
    cell.state = static_cast<Mark>(markValue);
    return is;
}

// Setteri și getteri
void Cell::setMark(Mark L)
{
    state = L;
}

Mark Cell::getMark() const
{
    return state;
}
