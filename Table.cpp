#include "Cell.hpp"
#include "Table.hpp"
#include <iostream>

// Constructor implicit
Table::Table()
{
    // Inițializează tabla cu celule goale
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cells[i][j] = Cell();
        }
    }
}

// Constructor de copiere
Table::Table(const Table& other)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cells[i][j] = other.cells[i][j];
        }
    }
}

// Constructor cu parametri
Table::Table(const Mark marks[rows][cols])
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cells[i][j].setMark(marks[i][j]);
        }
    }
}

// Operator de copiere
Table& Table::operator=(const Table& other)
{
    if (this != &other)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cells[i][j] = other.cells[i][j];
            }
        }
    }
    return *this;
}

// Operator de comparație
bool Table::operator==(const Table& other) const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (cells[i][j] != other.cells[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

// Operator de afișare
std::ostream& operator<<(std::ostream& os, const Table& table)
{
    for (int i = 0; i < Table::rows; ++i)
    {
        for (int j = 0; j < Table::cols; ++j)
        {
            switch (table.cells[i][j].getMark())
            {
                case Mark::X:
                    os << "X ";
                    break;
                case Mark::O:
                    os << "O ";
                    break;
                default:
                    os << "- ";
                    break;
            }
        }
        os << std::endl;
    }
    return os;
}

// Operator de citire
std::istream& operator>>(std::istream& is, Table& table)
{
    for (int i = 0; i < Table::rows; ++i)
    {
        for (int j = 0; j < Table::cols; ++j)
        {
            int markValue;
            is >> markValue;
            table.cells[i][j].setMark(static_cast<Mark>(markValue));
        }
    }
    return is;
}

// Afișează tabla
void Table::display() const
{
    std::cout << "  1 | 2 | 3\n";
    std::cout << " -----------\n";
    for (int i = 0; i < rows; ++i)
    {
        std::cout << i + 1 << " ";
        for (int j = 0; j < cols; ++j)
        {
            switch (cells[i][j].getMark())
            {
                case Mark::X:
                    std::cout << "| X ";
                    break;
                case Mark::O:
                    std::cout << "| O ";
                    break;
                default:
                    std::cout << "|   ";
                    break;
            }
        }
        std::cout << "|\n";
        std::cout << " -----------\n";
    }
}

// Verifică dacă o celulă este liberă
bool Table::isCellL(int row, int col) const
{
    return cells[row][col].getMark() == Mark::Gol;
}

// Actualizează o celulă cu un nou marcaj
void Table::updateCell(int row, int col, Mark newMark)
{
    cells[row][col].setMark(newMark);
}

// Returnează starea unei celule
Mark Table::getCell(int row, int col) const
{
    return cells[row][col].getMark();
}

// Verifică dacă tabla este plină
bool Table::isFull() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (cells[i][j].getMark() == Mark::Gol)
                return false;
        }
    }
    return true;
}
