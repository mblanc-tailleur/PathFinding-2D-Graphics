#pragma once
#include "Scene.h"
#include "Pathfinding/Grid.h"

class SampleScene : public Scene
{
    private:
        Grid grid;

    public:
        void OnInitialize() override;
        void OnUpdate() override;
};
