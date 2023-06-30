#ifndef __GAME_H__
#define __GAME_H__

#include <memory>
#include <stack>

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
}

class IScene;
enum class Event;

class Game {
public:
    Game();
    ~Game();
    void Run();
private:
    std::shared_ptr<IScene> CurrentScene();
    bool IsRunning();
    void HandleEvents();
    bool IsKeyPressed(SDL_Keycode key);
private:
    std::stack<std::shared_ptr<IScene>> scenes_;
    bool is_running_; //TODO: change this to atomic
    SDL_Event sdlevent_;
};

#endif