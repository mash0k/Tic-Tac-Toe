#pragma once
#include "Cell.hpp"
#include <iostream>

class Table
{
private:
    static const int rows = 3;
    static const int cols = 3;
    Cell cells[rows][cols];
    
public:
    Table();               
    void display() const;   
    bool isCellL(int row, int col) const;   
    void updateCell(int row, int col, Mark newMark); 
    Mark getCell(int row, int col) const;
    bool isFull() const;     
};