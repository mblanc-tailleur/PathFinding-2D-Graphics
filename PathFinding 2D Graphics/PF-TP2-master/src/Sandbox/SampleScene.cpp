#include "SampleScene.h"

#include "InputManager.h"
#include "Debug.h"

void SampleScene::OnInitialize()
{
	game.w = 10;
	game.h = 10;
	game.wallChance = 200;
	game.hillChance = 200;
	game.hillMaxHeight = 2;
	game.MakeGrid();

	game.grid[0][0].val = 0;
	game.start = { 0, 0 };
	game.grid[9][9].val = 0;
	game.end = { 9, 9 };


	f32 gw = f32(game.w);
	f32 gh = f32(game.h);

	f32 size = min(GetWindowWidth() / gw, GetWindowHeight() / gh);
	cellSize = { size, size };
}



void SampleScene::OnUpdate()
{
	InputManager* input = InputManager::Get();

	Vector2f mousePos = input->GetMousePosition();

	game.BreadthFirstSearch();

	DrawGrid();
    DrawCursor();

	if (input->IsKeyDown(SDLK_ESCAPE))
	{
		exit(0);
	}

	if (input->IsKeyDown(SDLK_Z))
	{
		game.MoveCursor(0, -1);
	}

	if (input->IsKeyDown(SDLK_Q))
	{
		game.MoveCursor(-1, 0);
	}

	if (input->IsKeyDown(SDLK_S))
	{
		game.MoveCursor(0, 1);
	}

	if (input->IsKeyDown(SDLK_D))
	{
		game.MoveCursor(1, 0);
	}

	if (input->IsKeyDown(SDLK_L))
	{
		game.start = game.cursor;
	}

	if (input->IsKeyDown(SDLK_M))
	{
		game.end = game.cursor;
	}

	if (input->IsKeyDown(SDLK_SPACE))
	{
		if (game.grid[game.cursor.x][game.cursor.y].val == 0)
		{
			game.grid[game.cursor.x][game.cursor.y].val = 1;
		}

		else
		{
			game.grid[game.cursor.x][game.cursor.y].val = 0;
		}
	}
}


void SampleScene::DrawGrid()
{
	for (i16 a = 0; a < game.w; a++)
	{
		for (i16 b = 0; b < game.h; b++)
		{
			DrawCell(a, b);
		}
	}
}

void SampleScene::DrawCell(i16 a, i16 b)
{
	Vector2f center = GetCenter(a, b);

	Color color;

	if (game.grid[a][b].val == 1)
	{
		color = { 0, 0, 0, 255 };
	}

	else if (game.grid[a][b].pos == game.start)
	{
		color = { 255, 0, 0, 255 };
	}

	else if (game.grid[a][b].pos == game.end)
	{
		color = { 0, 0, 255, 255 };
	}

	else
	{
		if (game.grid[a][b].checked == 2)
		{
			color = { 0, 255, 0, 255 };
		}

		else
		{
			color = { 255, 255, 255, 255 };
		}

		f32 colorChanger = f32(game.grid[a][b].hillHeight / 10.f);

		color.r *= f32(1 - colorChanger);
		color.g *= f32(1 - (colorChanger * 2.f));
		color.b *= f32(1 - (colorChanger * 3.f));
	}

	Debug::DrawRectangle(center, cellSize, color, true);
}


Vector2f SampleScene::GetCenter(i16 a, i16 b)
{
	Vector2f center = { f32(f32(f32(a - f32(f32(game.w - 1) / 2.f)) * cellSize.x) + (GetWindowWidth() / 2.f)), f32(f32(f32(b - f32(f32(game.h - 1) / 2.f)) * cellSize.y) + (GetWindowHeight() / 2.f)) };

	return center;
}

void SampleScene::DrawCursor()
{
	Color colorYellow = { 255, 255, 0, 255 };

	Vector2f sizeLarge = { cellSize.x, cellSize.y / 10.f };
	Vector2f sizeTall = { cellSize.x / 10.f, cellSize.y };

	Vector2f center = GetCenter(game.cursor.x, game.cursor.y);

	Debug::DrawRectangle({ center.x, center.y + (cellSize.y * 0.45f) }, sizeLarge, colorYellow, true);
	Debug::DrawRectangle({ center.x, center.y - (cellSize.y * 0.45f) }, sizeLarge, colorYellow, true);
	Debug::DrawRectangle({ center.x + (cellSize.y * 0.45f), center.y }, sizeTall, colorYellow, true);
	Debug::DrawRectangle({ center.x - (cellSize.y * 0.45f), center.y }, sizeTall, colorYellow, true);
}
