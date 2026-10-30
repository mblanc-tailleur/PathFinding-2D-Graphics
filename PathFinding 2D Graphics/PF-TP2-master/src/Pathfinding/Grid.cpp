#include "Grid.h"

#include <random>

void Grid::ConsoleDraw()
{
	cout << WHITE_WRITE << BLACK_BG;

	for (i16 b = 0; b < h; b++)
	{
		for (i16 a = 0; a < w; a++)
		{
			if ((a == cursor.x) and ((b == cursor.y) or (b == (cursor.y + 1))))
			{
				cout << YELLOW_WRITE << "+";
			}

			else if ((a == (cursor.x + 1)) and ((b == cursor.y) or (b == (cursor.y + 1))))
			{
				cout << YELLOW_WRITE << "+" << WHITE_WRITE;
			}

			else
			{
				cout << "+";
			}

			cout << "---" << WHITE_WRITE;

		}

		if ((w == cursor.x + 1) and ((b == cursor.y) or (b == cursor.y + 1)))
		{
			cout << YELLOW_WRITE << "+" << WHITE_WRITE << endl;
		}

		else
		{
			cout << "+" << endl;
		}

		for (i16 a = 0; a < w; a++)
		{
			if (((a == cursor.x) or (a == (cursor.x + 1))) and (b == cursor.y))
			{
				cout << YELLOW_WRITE << "|" << WHITE_WRITE;
			}

			else
			{
				cout << "|";
			}

			if (grid[a][b].val == 0)
			{
				if (grid[a][b].checked == 2)
				{
					cout << GREEN_BG;
				}

				if ((a == start.x) and (b == start.y))
				{
					cout << RED_WRITE << "STA" << WHITE_WRITE;
				}

				else if ((a == end.x) and (b == end.y))
				{
					cout << BLUE_WRITE << "END" << WHITE_WRITE;
				}

				else
				{
					cout << "   ";
				}

				cout << BLACK_BG;
			}

			else if (grid[a][b].val == 1)
			{
				cout << "XXX";
			}
		}

		if ((w == (cursor.x + 1)) and (b == cursor.y))
		{
			cout << YELLOW_WRITE << "|" << WHITE_WRITE << endl;
		}

		else
		{
			cout << "|" << endl;
		}
	}

	for (i16 a = 0; a < w; a++)
	{
		if ((a == cursor.x) and ((h == cursor.y) or (h == (cursor.y + 1))))
		{
			cout << YELLOW_WRITE << "+";
		}

		else if ((a == (cursor.x + 1)) and ((h == cursor.y) or (h == (cursor.y + 1))))
		{
			cout << YELLOW_WRITE << "+" << WHITE_WRITE;
		}

		else
		{
			cout << "+";
		}

		cout << "---" << WHITE_WRITE;
	}

	if ((w == (cursor.x + 1)) and (h == (cursor.y + 1)))
	{
		cout << YELLOW_WRITE << "+" << WHITE_WRITE << endl;
	}

	else
	{
		cout << "+" << endl;
	}
}

i16 Grid::GetValue(v2i16 pos)
{
	return grid[pos.x][pos.y].val;
}

void Grid::push_back(vector<Cell> newVect)
{
	grid.push_back(newVect);
}

void Grid::MakeGrid()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<f32> dis(0, 1);
    std::uniform_int_distribution<i16> hillDis(1, hillMaxHeight);

	for (i16 a = 0; a < w; a++)
	{
		vector<Cell> v;

		for (i16 b = 0; b < h; b++)
		{
			Cell c;
			f32 randF = dis(gen);

			if (randF < wallChance)
			{
				c.val = 1;
			}

			else 
			{
				if ((wallChance < randF) and (randF < (wallChance + hillChance)))
				{
					c.hillHeight = hillDis(gen);
				}

				else
				{
					c.hillHeight = 0;
				}

				c.val = 0;
			}

            c.previous = nullptr;
            c.next = {};
            c.checked = 0;
			c.pos = { a, b };

			v.push_back(c);
		}

		grid.push_back(v);
	}
}

void Grid::BreadthFirstSearch()
{
	for (i16 b = 0; b < h; b++)
	{
		for (i16 a = 0; a < w; a++)
		{
			grid[a][b].checked = 0;
			grid[a][b].previous = nullptr;
			grid[a][b].next = {};
		}
	}

	vector<Cell*> added;
	vector<Cell*>* pAdded = &added;

	added.push_back(&grid[start.x][start.y]);

	i16 step = 1;

	bool keepGoing1 = true;

	while (keepGoing1 == true)
	{
		Cell* act = added[0];

		if (CheckAdjacentCells(i16(act->pos.x - step), act->pos.y, pAdded) == true)
		{
			act->AddNext();
			added.push_back(&grid[i16(act->pos.x - step)][act->pos.y]);
			act->next.push_back(&grid[i16(act->pos.x - step)][act->pos.y]);
		}

		if (CheckAdjacentCells(i16(act->pos.x + step), act->pos.y, pAdded) == true)
		{
			added.push_back(&grid[i16(act->pos.x + step)][act->pos.y]);
			act->next.push_back(&grid[i16(act->pos.x + step)][act->pos.y]);
		}

		if (CheckAdjacentCells(act->pos.x, i16(act->pos.y - step), pAdded) == true)
		{
			added.push_back(&grid[act->pos.x][i16(act->pos.y - step)]);
			act->next.push_back(&grid[act->pos.x][i16(act->pos.y - step)]);
		}

		if (CheckAdjacentCells(act->pos.x, i16(act->pos.y + step), pAdded) == true)
		{
			added.push_back(&grid[act->pos.x][i16(act->pos.y + step)]);
			act->next.push_back(&grid[act->pos.x][i16(act->pos.y + step)]);
		}

		for (i16 k = 0; k < act->next.size(); k++)
		{
			act->next[k]->previous = act;
		}

		if (act->pos == end)
		{
			Cell* current = act;

			bool keepGoing2 = true;

			while (keepGoing2 == true)
			{
				current->checked = 2;

				if (current->previous == nullptr)
				{
					keepGoing2 = false;
				}

				else if (current->previous->pos == start)
				{
					keepGoing2 = false;
				}

				current = current->previous;
			}

			current->checked = 2;

			added.clear();
		}

		else
		{
			act->checked = 1;
			added.erase(added.begin());
		}

		if (added.size() < 1)
		{
			keepGoing1 = false;
			break;
		}
	}
}

bool Grid::CheckAdjacentCells(i16 x, i16 y, vector<Cell*>* pAdded)
{
	if (IsCellInBounds(x, y) == true)
	{
		if (grid[x][y].val == 0)
		{
			if (IsCellInVector(&grid[x][y], pAdded) == false)
			{
				if (grid[x][y].checked == 0)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool Grid::IsCellInBounds(i16 x, i16 y)
{
	if (((x < 0) or (x >= w)) or ((y < 0) or (y >= h)))
	{
		return false;
	}

	return true;
}

bool Grid::IsCellInVector(Cell* pCell, vector<Cell*>* pVect)
{
	for (i16 i = 0; i < pVect->size(); i++)
	{
		if ((*pVect)[i]->pos == pCell->pos)
		{
			return true;
		}
	}

	return false;
}

