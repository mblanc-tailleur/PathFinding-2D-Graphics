#include "SampleScene.h"

#include "DummyEntity.h"
#include "InputManager.h"
#include "Debug.h"

void SampleScene::OnInitialize()
{
    game.w = 10;
    game.h = 10;
	game.wallChance = 0.2f;
	game.hillChance = 0.2f;
    game.hillMaxHeight = 2;
	game.MakeGrid();

	f32 gw = f32(game.w);
	f32 gh = f32(game.h);

	f32 size = min(GetWindowWidth() / gw, GetWindowHeight() / gh);
	cellSize = { size, size };


	/*
	mpEntity1 = CreateEntity<DummyEntity>(40.f, Color::Cyan);
	mpEntity1->SetPosition({ 300.f, 360.f });
	mpEntity1->SetRigidBody(true);

	mpEntity2 = CreateEntity<DummyEntity>(60.f, Color::Orange);
	mpEntity2->SetPosition({ 700.f, 360.f });
	mpEntity2->SetRigidBody(true);
	*/

}



void SampleScene::OnUpdate()
{
	InputManager* input = InputManager::Get();

	Vector2f mousePos = input->GetMousePosition();

    DrawGrid();


    /*
	if (input->IsMouseDown(SDL_BUTTON_LEFT))
	{
		if (mpEntity1->IsPointInside(mousePos))
		{
			mpSelectedEntity = mpEntity1;
		}
		else if (mpEntity2->IsPointInside(mousePos))
		{
			mpSelectedEntity = mpEntity2;
		}
		else if (mpSelectedEntity != nullptr)
		{
			mpSelectedEntity->GoTo(mousePos, 200.f);
		}
	}

	if (mpSelectedEntity != nullptr)
	{
		Debug::DrawCircle(mpSelectedEntity->GetPosition(), 5.f, Color::Magenta, true);
	}*/
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
