#include <thread>
#include "game.h"
//-----------------------------------------------------------------------------
constexpr unsigned int W_WIDTH = 512;//1024;
constexpr unsigned int W_HEIGHT = 384;//768;
//-----------------------------------------------------------------------------
Game::Game() : is_running_(false)
{
    window_ = std::make_shared<Window>(W_WIDTH, W_HEIGHT);
    // world_  = std::make_unique<World>(W_WIDTH/16, W_HEIGHT/16);
    // world_->ProceduralGeneration();
    // world_->Draw();
}
//-----------------------------------------------------------------------------
void Game::Run()
{
    is_running_ = true;

    while(IsRunning())
    {
        while (SDL_PollEvent(&event_))
        {
            switch(event_.type)
            {
                case SDL_QUIT:
                    is_running_ = false;
                    break;
                default:
                    std::cout << "w title: " << CurrentWindow().get()->GetTitle() << std::endl;
                    break;
            }
        }

    }
    // window_->Run();
}
//-----------------------------------------------------------------------------
std::shared_ptr<Window> Game::CurrentWindow()
{
    return window_;
}
//-----------------------------------------------------------------------------
bool Game::IsRunning()
{
    return is_running_;
}
//-----------------------------------------------------------------------------
