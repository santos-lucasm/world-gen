#include <thread>
#include "game.h"

constexpr unsigned int W_WIDTH = 1024;
constexpr unsigned int W_HEIGHT = 768;


Game::Game()
{
    window_ = std::make_unique<Window>(W_WIDTH, W_HEIGHT);
    world_  = std::make_unique<World>(W_WIDTH/16, W_HEIGHT/16);
    // w.ProceduralGeneration();
    // w.Draw();

}

void Game::Run()
{
    // std::thread game_t(&Game::Run, this);
    std::this_thread::sleep_for(std::chrono::seconds(2));
}