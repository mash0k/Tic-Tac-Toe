#pragma once
#include "Cell.hpp"
#include <iostream>

class Table1 {
public:
    virtual ~Table1() = default; // Destructor virtual

    virtual void display() const = 0; 
    virtual bool isCellL(int row, int col) const = 0; 
    virtual void updateCell(int row, int col, Mark newMark) = 0;
};


class Table
{
private:
    static const int rows = 3;
    static const int cols = 3;
    Cell cells[rows][cols];

public:
    // Constructori
    Table();                             // Constructor implicit
    Table(const Table& other);           // Constructor de copiere
    Table(const Mark marks[rows][cols]); // Constructor cu parametri

    // Operator de copiere
    Table& operator=(const Table& other);

    // Operator de comparație
    bool operator==(const Table& other) const;

    // Operator de afișare
    friend std::ostream& operator<<(std::ostream& os, const Table& table);

    // Operator de citire
    friend std::istream& operator>>(std::istream& is, Table& table);

    // Funcții adiționale
    void display() const;
    bool isCellL(int row, int col) const;
    void updateCell(int row, int col, Mark newMark);
    Mark getCell(int row, int col) const;
    bool isFull() const;
};