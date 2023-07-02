#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <memory>
#include <stack>

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
}

constexpr unsigned int W_WIDTH = 1024;
constexpr unsigned int W_HEIGHT = 768;

class IScene;
class IApplicationState;

class Application
{
public:
    Application();
    ~Application();
    void Run();
    SDL_Event CurrentEvent();
    void ChangeScene(std::shared_ptr<IScene> scene);
    void ChangeState(IApplicationState* state);
private:
    std::shared_ptr<IScene> CurrentScene();
    bool IsRunning();
    void HandleEvents();
private:
    std::stack<std::shared_ptr<IScene>> scenes_;
    IApplicationState* state_;
    bool is_running_; //TODO: change this to atomic
    SDL_Event sdlevent_;
};

#endif