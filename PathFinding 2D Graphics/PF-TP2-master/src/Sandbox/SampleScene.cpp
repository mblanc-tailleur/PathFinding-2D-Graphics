#include "SampleScene.h"

#include "DummyEntity.h"
#include "InputManager.h"
#include "Debug.h"

void SampleScene::OnInitialize()
{
	game.w = 10;
	game.h = 10;

	game.MakeGrid();

	f32 cellMinSize = min(GetWindowWidth() / game.w, GetWindowHeight() / game.h);
	cellSize = { cellMinSize, cellMinSize };

	/*
	mpEntity1 = CreateEntity<DummyEntity>(40.f, Color::Cyan);
	mpEntity1->SetPosition({ 300.f, 360.f });
	mpEntity1->SetRigidBody(true);

	mpEntity2 = CreateEntity<DummyEntity>(60.f, Color::Orange);
	mpEntity2->SetPosition({ 700.f, 360.f });
	mpEntity2->SetRigidBody(true);
	*/
	
}

Vector2f SampleScene::GetCellWorldPos(i16 a, i16 b)
{
    f32 newX = (cellSize.x * f32(a - f32(f32(game.w - 1) / 2.f))) + (GetWindowWidth() / 2);
    f32 newY = (cellSize.y * f32(b - f32(f32(game.h - 1) / 2.f))) + (GetWindowHeight() / 2);
}

void SampleScene::OnUpdate()
{
	InputManager* input = InputManager::Get();

	if (input->IsKeyDown(SDLK_ESCAPE))
	{
		exit(0);
	}

	if (input->IsKeyDown(SDLK_L))
	{


	}



	/*
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
		*/
	/*
	Vector2f mousePos = input->GetMousePosition();

	Debug::DrawText({ 10.f, 10.f }, "Clic gauche : selectionner un cercle, puis cliquer pour le déplacer.", Color::White);
	if (mpSelectedEntity != nullptr)
	{
		Debug::DrawCircle(mpSelectedEntity->GetPosition(), 5.f, Color::Magenta, true);

	}
	*/
}

void SampleScene::DrawGrid()
{
	for (i16 b = 0; b < game.h; b++)
	{
		for (i16 a = 0; a < game.w; a++)
		{
			if (game.grid[a][b].val == 0)
			{
				if (game.grid[a][b].checked == 0)
				{
					Debug::DrawRectangle(cellSize, )
				}

				else if (game.grid[a][b].checked == 2)
				{

				}
			}

			else if (game.grid[a][b].val == 1)
			{

			}
		}
	}
}
