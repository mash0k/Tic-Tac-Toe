#pragma once
#include "Mark.hpp"


class Cell
{
private:
    Mark state;

public:
    Cell() : state(Mark::Gol) {}

    void setMark(Mark L)
    {
        state = L;
    }

    Mark getMark() const
    {
        return state;
    }
};