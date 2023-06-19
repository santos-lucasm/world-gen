#ifndef __GAME_H__
#define __GAME_H__

#include <memory>
#include <stack>
#include "windows/window.h"

class Game {
public:
    Game();

    void Run();

    std::shared_ptr<Window> CurrentWindow();

    bool IsRunning();
private:
    std::stack<std::shared_ptr<Window>> windows_;
    bool is_running_; //TODO: change this to atomic
    SDL_Event event_;
};

#endif