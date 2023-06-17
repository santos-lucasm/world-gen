#include "window.h"

Window::Window(const unsigned int size_w, const unsigned int size_h)
    : window_(nullptr)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return;
    }

    window_ = SDL_CreateWindow( "world-gen",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                size_w, size_h, 0);
}