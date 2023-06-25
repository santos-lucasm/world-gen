#include "game.h"
#include "scenes/main_scene.h"
#include "events/event_manager.h"
//-----------------------------------------------------------------------------
constexpr unsigned int W_WIDTH = 1024;
constexpr unsigned int W_HEIGHT = 768;
//-----------------------------------------------------------------------------
Game::Game() : is_running_(false)
{
    if (SDL_Init(SDL_INIT_EVENTS) != 0)
    {
        //TODO: handle err
        return;
    }

    scenes_.push(std::make_shared<MainScene>(W_WIDTH, W_HEIGHT));
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
        while (SDL_PollEvent(&sdlevent_))
        {
            HandleEvents();
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
void Game::HandleEvents()
{
    static bool pause_button_already_entered_ = false;

    if(sdlevent_.type == SDL_QUIT)
    {
        is_running_ = false;
    }
    else if(IsKeyPressed(SDLK_ESCAPE))
    {
        pause_button_already_entered_ = !pause_button_already_entered_;
        EventManager::Instance()->NotifyPauseTriggered(Event::PAUSE_TRIGGERED, pause_button_already_entered_);
    }
    else if(IsKeyPressed(SDLK_SPACE))
    {
        
    }
}
//-----------------------------------------------------------------------------
bool Game::IsKeyPressed(SDL_Keycode key)
{
    if(sdlevent_.type == SDL_KEYDOWN && sdlevent_.key.repeat == 0
        && sdlevent_.key.keysym.sym == key)
    {
        return true;
    }
    return false;
}
//-----------------------------------------------------------------------------
