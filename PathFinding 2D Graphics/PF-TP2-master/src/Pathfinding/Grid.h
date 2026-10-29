#pragma once

#include "Cell.h"
#include "utils.h"

class Grid
{
    public:
        i16 w;
        i16 h;

        vector<vector<Cell>> grid;

        v2i16 start;
        v2i16 end;
        v2i16 cursor;

        void ConsoleDraw();
        i16 GetValue(v2i16 pos);
        void push_back(vector<Cell> newVect);

        void MakeGrid();

        void BreadthFirstSearch();
        bool CheckAdjacentCells(i16 x, i16 y, vector<Cell*>* pAdded);
        bool IsCellInBounds(i16 x, i16 y);
        bool IsCellInVector(Cell* pCell, vector<Cell*>* pVect);

        /*
        si i16 == 0, case vide
        si i16 == 1, mur
        */
};
