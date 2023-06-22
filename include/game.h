#ifndef __GAME_H__
#define __GAME_H__

#include <memory>
#include <stack>
#include "scenes/scene.h"

enum class Event;

class Game {
public:
    Game();

    void Run();

    std::shared_ptr<Scene> CurrentWindow();

    bool IsRunning();
private:
    std::stack<std::shared_ptr<Scene>> windows_;
    bool is_running_; //TODO: change this to atomic
    SDL_Event sdlevent_;
    Event game_event_;
};

#endif