#include "game.h"
#include "scenes/main_scene.h"
#include "events/event_types.h"
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

    scenes_.push(std::make_shared<MainScene>(W_WIDTH, W_HEIGHT));
    ev_manager_ = std::make_unique<EventManager>();
    ev_manager_->Subscribe(Event::PAUSE_TRIGGERED, dynamic_cast<EventListener*>(CurrentScene().get()));
}
//-----------------------------------------------------------------------------
Game::~Game()
{
    while(!scenes_.empty())
    {
        scenes_.pop();
    }
    SDL_Quit();
}
//-----------------------------------------------------------------------------
void Game::Run()
{
    is_running_ = true;

    while(IsRunning())
    {
        //TODO: this loop will cover big events and commands such as "CLOSE"
        //other events should be passed to be handled by the current window
        while (SDL_PollEvent(&sdlevent_))
        {
            switch(sdlevent_.type)
            {
                case SDL_QUIT:
                    is_running_ = false;
                    break;
                case SDL_KEYDOWN:
                    if( sdlevent_.key.repeat == 0 && sdlevent_.key.keysym.sym == 32 )
                    {
                        ev_manager_->NotifyPauseTriggered(Event::PAUSE_TRIGGERED, true);
                    }
                    break;
                case SDL_KEYUP:
                    if( sdlevent_.key.repeat == 0 && sdlevent_.key.keysym.sym == 32 )
                    {
                        ev_manager_->NotifyPauseTriggered(Event::PAUSE_TRIGGERED, false);
                    }
                    break;
                default:
                    break;
            }
        }
        
        CurrentScene()->Draw();
        SDL_Delay( 1000 / 60 ); // 60fps
    }
}
//-----------------------------------------------------------------------------
std::shared_ptr<Scene> Game::CurrentScene()
{
    return scenes_.top();
}
//-----------------------------------------------------------------------------
bool Game::IsRunning()
{
    return is_running_;
}
//-----------------------------------------------------------------------------
