#include "GameManager.h"
#include "SampleScene.h"

int main()
{
    GameManager* game = GameManager::Get();

    game->LaunchScene<SampleScene>(1080, 540, "SampleScene", Color{ 25, 25, 35 });

    return 0;
}
