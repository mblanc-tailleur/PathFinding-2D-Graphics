#include "GameManager.h"
#include "SampleScene.h"

int main()
{
    GameManager* game = GameManager::Get();

    game->LaunchScene<SampleScene>(1920, 1080, "SampleScene", Color{ 0, 0, 0 });

    return 0;
}
