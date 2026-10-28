#pragma once
#include "utils.h"

class Cell;
class InputManager;

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
        void MakeGrid(f32 wallPercentage);
		void push_back(vector<Cell> newVect);
        void UpdateInput(InputManager* pInput);

		

		/*
		si i16 == 0, case vide
		si i16 == 1, mur
		*/
};

