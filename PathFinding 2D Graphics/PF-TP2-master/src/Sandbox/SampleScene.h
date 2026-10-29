#pragma once

#include "Scene.h"
#include "Pathfinding/Grid.h"

class SampleScene : public Scene
{
	/*DummyEntity* mpEntity1 = nullptr;
	DummyEntity* mpEntity2 = nullptr;

	DummyEntity* mpSelectedEntity = nullptr;*/

	public:
		Grid game;

		Vector2f cellSize;

		void OnInitialize() override;
        void GetCellWorldPos(i16 x, i16 y);
		void OnUpdate() override;
		void DrawGrid();
};
