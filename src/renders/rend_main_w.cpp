#include "renders/rend_main_w.h"

RenderMainWindow::RenderMainWindow(SDL_Window* window)
    : sdl_renderer_(NULL)
{
    // triggers the program that controls your graphics hardware and sets flags
    // creates a renderer to render our images
    sdl_renderer_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!sdl_renderer_)
    {
        //TODO: handle err
        return;
    }
}

RenderMainWindow::~RenderMainWindow()
{
    SDL_DestroyRenderer(sdl_renderer_);
}

void RenderMainWindow::Render()
{
    // Set render color to red ( background will be rendered in this color )
    int res;
    res = SDL_SetRenderDrawColor(sdl_renderer_, 255, 0, 0, 255);

    // clears the screen
    res = SDL_RenderClear(sdl_renderer_);

    SDL_Rect r;
    r.w = 16;
    r.h = 16;
    r.x = 16;
    r.y = 16;

    // Set render color to blue ( rect will be rendered in this color )
    res = SDL_SetRenderDrawColor(sdl_renderer_, 0, 0, 255, 255);

    // Render rect
    res = SDL_RenderFillRect(sdl_renderer_, &r);

    // Render the rect to the screen
    SDL_RenderPresent(sdl_renderer_);
}