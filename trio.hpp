#pragma once
#include "vertex.hpp"

class trio
{
    public:
    vertex v[3];
    friend ostream& operator<<(ostream& os, const trio& t);
};
