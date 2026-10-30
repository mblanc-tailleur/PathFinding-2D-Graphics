#include "Cell.h"

void Cell::AddNext(Cell* newNext)
{
    next.push_back(newNext);
}
