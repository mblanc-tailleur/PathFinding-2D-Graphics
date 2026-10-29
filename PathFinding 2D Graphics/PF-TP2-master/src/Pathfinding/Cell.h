#pragma once

#include "utils.h"
#include <vector>

class Cell
{
    public:
        i8 checked = 0;
        i16 val = 0;
        v2i16 pos;
        Cell* previous;
        vector<Cell*> next;
};
