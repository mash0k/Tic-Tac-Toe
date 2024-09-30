#pragma once
#include "Mark.hpp"

class Cell
{
private:
    Mark state;

public:
    Cell();
    void setMark(Mark L);
    Mark getMark() const;
};
