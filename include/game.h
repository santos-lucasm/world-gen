#ifndef __GAME_H__
#define __GAME_H__

#include <memory>
#include <stack>
// #include "scenes/scene.h"

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

class Scene;
enum class Event;

class Game {
public:
    Game();

    ~Game();

    void Run();

    std::shared_ptr<Scene> CurrentScene();

    bool IsRunning();
private:
    std::stack<std::shared_ptr<Scene>> scenes_;
    bool is_running_; //TODO: change this to atomic
    SDL_Event sdlevent_;
    Event game_event_;
};

#endif