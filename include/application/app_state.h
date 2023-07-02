#ifndef __APPLICATION_STATE_H__
#define __APPLICATION_STATE_H__

extern "C" {
    #include <SDL2/SDL.h>
}

class Application;

class IApplicationState {
public:
    IApplicationState(Application* app);

    ~IApplicationState();

    virtual void HandleEvents() = 0;
protected:
    bool IsKeyPressed(SDL_Keycode key);
    SDL_Event Event();
    Application* app_;
};

#endif