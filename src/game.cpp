#include <thread>
#include "game.h"
#include "scenes/main_scene.h"
#include "fsm/event_types.h"
#include <iostream>
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
    CurrentScene()->Update(Event::START_MAINSCENE_EXEC);
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
                        game_event_ = Event::PAUSE_PROCEDURAL_GENERATION;
                    }
                    break;
                case SDL_KEYUP:
                    if( sdlevent_.key.keysym.sym == 32 )
                    {
                        game_event_ = Event::RESUME_PROCEDURAL_GENERATION;
                    }
                    break;
                default:
                    break;
            }
            CurrentScene()->Update(game_event_);
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
