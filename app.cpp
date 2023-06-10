#include "world.h"

int main()
{
    std::cout << "Starting app" << std::endl;
    World w(60, 40);
    w.ProceduralGeneration();
    w.Draw();
    std::cout << "Finishing app" << std::endl;
    return 0;
}