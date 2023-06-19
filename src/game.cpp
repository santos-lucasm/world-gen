#include <thread>
#include "game.h"
#include "windows/main_w.h"
//-----------------------------------------------------------------------------
constexpr unsigned int W_WIDTH = 1024;
constexpr unsigned int W_HEIGHT = 768;
//-----------------------------------------------------------------------------
Game::Game() : is_running_(false)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        //TODO: handle err
        return;
    }

    windows_.push(std::make_shared<MainWindow>(W_WIDTH, W_HEIGHT));
    renderer_ = std::make_unique<Renderer>(CurrentWindow());
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
                    break;
            }
        }
        
        CurrentWindow()->Update();
        renderer_->Render();

        SDL_Delay( 1000 / 60 ); // 60fps
    }
}
//-----------------------------------------------------------------------------
std::shared_ptr<Window> Game::CurrentWindow()
{
    return windows_.top();
}
//-----------------------------------------------------------------------------
bool Game::IsRunning()
{
    return is_running_;
}
//-----------------------------------------------------------------------------
