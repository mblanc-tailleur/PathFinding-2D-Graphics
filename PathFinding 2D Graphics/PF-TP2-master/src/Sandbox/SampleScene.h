#pragma once

#include "Scene.h"
#include "Pathfinding/Grid.h"

class SampleScene : public Scene
{
    public:
        Grid game;
        Vector2f cellSize;


        void OnInitialize() override;
        void OnUpdate() override;
        void DrawGrid();
        void DrawCell(i16 a, i16 b);
        Vector2f GetCenter(i16 a, i16 b);
        void DrawCursor();
};
