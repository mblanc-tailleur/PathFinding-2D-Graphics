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

	f32 gw = f32(game.w);
	f32 gh = f32(game.h);

	f32 size = min(GetWindowWidth() / gw, GetWindowHeight() / gh);
	cellSize = { size, size };
}



void SampleScene::OnUpdate()
{
	InputManager* input = InputManager::Get();

	Vector2f mousePos = input->GetMousePosition();

	DrawGrid();

	if (input->IsKeyDown(SDLK_L))
	{

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
	Vector2f center = { f32(f32(f32(f32(f32(game.w - 1) / 2.f) - a) * cellSize.x) + GetWindowWidth()), f32(f32(f32(f32(f32(game.h - 1) / 2.f) - b) * cellSize.y) + GetWindowHeight()) };

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
		if (game.grid[a][b].checked == 1)
		{
			color = { 255, 255, 0, 255 };
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
