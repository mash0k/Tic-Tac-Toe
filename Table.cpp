#pragma once
#include "Cell.hpp"
#include "Table.hpp"
#include <iostream>

class Table
{
private:
    static const int rows = 3;
    static const int cols = 3;
    Cell cells[rows][cols];
    
public:

    Table()
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

    void display() const
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

    bool isCellL(int row, int col) const
    {
        return cells[row][col].getMark() == Mark::Gol;
    }

    void updateCell(int row, int col, Mark newMark)
    {
        cells[row][col].setMark(newMark);
    }

    Mark getCell(int row, int col) const
    {
        return cells[row][col].getMark();
    }

    bool isFull() const
    {
        // Check if all cells are filled (no more empty cells)
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

};

