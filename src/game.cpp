#include <thread>
#include "game.h"
#include "ev_handler.h"
//-----------------------------------------------------------------------------
constexpr unsigned int W_WIDTH = 1024;
constexpr unsigned int W_HEIGHT = 768;
//-----------------------------------------------------------------------------
Game::Game()
{
    window_ = std::make_shared<Window>(W_WIDTH, W_HEIGHT);
    world_  = std::make_unique<World>(W_WIDTH/16, W_HEIGHT/16);

    world_->ProceduralGeneration();
    world_->Draw();
}
//-----------------------------------------------------------------------------
void Game::Run()
{
    //TODO: create threads vector when needed
    auto ev_handler = std::make_unique<EventHandler>(this);
    std::thread game_t(&EventHandler::Run, ev_handler.get());

    while(ev_handler->IsRunning());
    game_t.join();
    std::cout << "game ended" << std::endl;
}
//-----------------------------------------------------------------------------
std::shared_ptr<Window> Game::CurrentWindow()
{
    return window_;
}
//-----------------------------------------------------------------------------