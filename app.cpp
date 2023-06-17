#include "game.h"
#include <thread>

int main()
{
    //TODO: This should be a class

    std::cout << "Starting app" << std::endl;
    Game world_gen = Game();
    world_gen.Run();
    std::cout << "Finishing app" << std::endl;
    return 0;
}