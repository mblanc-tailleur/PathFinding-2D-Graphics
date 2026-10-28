#pragma once

class Grid;

class Cell
{
	public:
		i8 checked = 0;
		i16 val = 0;
        v2i16 pos = { 0, 0 };
		Cell* previous = nullptr;
        vector<Cell*> next = {};

		void BreadthFirstSearch(v2i16 goalPos, Grid* pGrid);
		bool CheckAdjacentCells(i16 x, i16 y, vector<Cell*>* pAdded, Grid* pGrid);
		bool IsCellInBounds(i16 x, i16 y, Grid* pGrid);
		bool IsCellInVector(Cell* pCell, vector<Cell*>* pVect);
};
