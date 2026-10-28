#include "Grid.h"
#include "Cell.h"
#include "LightEngine/InputManager.h"

void Grid::ConsoleDraw()
{
	system("cls");

	for (i16 a = 0; a < h; a++)
	{
		for (i16 b = 0; b < w; b++)
		{
			cout << "+---";
		}

		cout << "+" << endl;

		for (i16 b = 0; b < w; b++)
		{
			cout << "|";

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

		cout << "|" << endl;
	}

	for (i16 b = 0; b < w; b++)
	{
		cout << "+---";
	}

	cout << "+";
}

i16 Grid::GetValue(v2i16 pos)
{
	return grid[pos.x][pos.y].val;
}

void Grid::MakeGrid(f32 wallPercentage)
{
    std::uniform_int_distribution<f32> dis(0, 1);

    for (i16 a = 0; a < h; a++)
    {
        vector<Cell> v;

        for (i16 b = 0; b < w; b++)
        {
            Cell c;
            f32 f = dis(gen);

            if (f > wallPercentage)
            {
                c.val = 0;
            }

            else
            {
                c.val = 1;
            }

            c.pos = { a, b };

            v.push_back(c);
        }

        grid.push_back(v);
    }
}

void Grid::push_back(vector<Cell> newVect)
{
	grid.push_back(newVect);
}

void Grid::UpdateInput(InputManager* pInput)
{
    if (pInput->IsKeyDown(SDLK_5))
    {

    }
}
