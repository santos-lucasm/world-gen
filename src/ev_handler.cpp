#include "ev_handler.h"
#include "game.h"
#include <iostream>
#include <thread>
//-----------------------------------------------------------------------------
EventHandler::EventHandler(Game* game)
    : game_(game)
{
    // is_running_.store(false, std::memory_order_release);
}
//-----------------------------------------------------------------------------
void EventHandler::Run()
{
    is_running_.store(true, std::memory_order_release);

    while(IsRunning())
    {
        while (SDL_PollEvent(&event_))
        {
            switch(event_.type)
            {
                case SDL_QUIT:
                    is_running_.store(false, std::memory_order_release);
                    break;
                default:
                    std::cout << "w title: " << game_->CurrentWindow().get()->GetTitle() << std::endl;
                    break;
            }
        }

    }
}
//-----------------------------------------------------------------------------
bool EventHandler::IsRunning()
{
    return is_running_.load(std::memory_order_acquire);
}
//-----------------------------------------------------------------------------
