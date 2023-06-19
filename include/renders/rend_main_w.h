#ifndef __REND_MAIN_W_H__
#define __REND_MAIN_W_H__

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

#include <memory>
#include "windows/main_w.h"

class RenderMainWindow {
public:
    RenderMainWindow(SDL_Window* window);

    ~RenderMainWindow();

    void Render();
private:
    SDL_Texture* texture_;
    SDL_Renderer* sdl_renderer_;
};

#endif