#pragma once
#include "Mark.hpp"
#include <iostream>

class Cell
{
private:
    Mark state;

public:
    // Constructor implicit
    Cell();

    // Constructor de copiere
    Cell(const Cell& other);

    // Constructor cu parametri
    Cell(Mark state);

    // Operator de copiere
    Cell& operator=(const Cell& other);

    // Operator de comparație
    bool operator==(const Cell& other) const;

    // Operator diferit de
    bool operator!=(const Cell& other) const;

    // Operator de afișare
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

    // Operator de citire
    friend std::istream& operator>>(std::istream& is, Cell& cell);

    // Setteri și getteri
    void setMark(Mark L);
    Mark getMark() const;
};
