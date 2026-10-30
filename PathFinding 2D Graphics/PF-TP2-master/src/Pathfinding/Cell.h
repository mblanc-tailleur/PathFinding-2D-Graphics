#pragma once

#include "utils.h"
#include <vector>

class Cell
{
	public:
        i16 val;
        v2i16 pos;
        i16 hillHeight;

        i8 checked;
        Cell* previous;
        vector<Cell*> next;

        void AddNext();
};
