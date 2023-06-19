#ifndef __RENDERER_H__
#define __RENDERER_H__

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

#include <memory>
#include "windows/window.h"

class Renderer {
public:
    Renderer(std::shared_ptr<Window> window);

    ~Renderer();

    void Render();
private:
    std::shared_ptr<Window> window_;
    SDL_Texture* texture_;
    SDL_Renderer* renderer_;
};

#endif