#ifndef __GAME_H__
#define __GAME_H__

#include <memory>
#include <atomic>
#include "window.h"
#include "world.h"

class Game {
public:
    Game();

    void Run();

    std::shared_ptr<Window> CurrentWindow();

    bool IsRunning();
private:
    std::shared_ptr<Window> window_;
    std::unique_ptr<World> world_;
    bool is_running_; //TODO: change this to atomic
    SDL_Event event_;
};

#endif