#ifndef __REND_MAIN_W_H__
#define __REND_MAIN_W_H__

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

#include <memory>
#include "windows/window.h"

class RenderMainWindow {
public:
    RenderMainWindow(std::shared_ptr<Window> window);

    ~RenderMainWindow();

    void Render();
private:
    std::shared_ptr<Window> window_;
    SDL_Texture* texture_;
    SDL_Renderer* renderer_;
};

#endif