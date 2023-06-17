#include "world.h"
#include "window.h"
#include <thread>

#define W_WIDTH 1024
#define W_HEIGHT 768

int main()
{
    //TODO: This should be a class

    std::cout << "Starting app" << std::endl;
    Window(W_WIDTH, W_HEIGHT);

    World w(W_WIDTH/16, W_HEIGHT/16);
    w.ProceduralGeneration();
    w.Draw();

    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Finishing app" << std::endl;
    return 0;
}