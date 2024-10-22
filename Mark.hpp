#pragma once

enum Mark
{
     Gol, X, O
};

// Operator de comparație pentru Mark
inline bool operator!=(Mark lhs, Mark rhs) {
    return static_cast<int>(lhs) != static_cast<int>(rhs);
}
