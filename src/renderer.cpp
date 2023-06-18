#include "renderer.h"

Renderer::Renderer(std::shared_ptr<Window> window)
    : renderer_(NULL), window_(window)
{
    // triggers the program that controls your graphics hardware and sets flags
    // creates a renderer to render our images
    renderer_ = SDL_CreateRenderer(window_->GetSdlRef(), -1, SDL_RENDERER_ACCELERATED);
    if(!renderer_)
    {
        //TODO: handle err
        return;
    }
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer_);
}

void Renderer::Render()
{
    // Set render color to red ( background will be rendered in this color )
    int res;
    res = SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);

    // clears the screen
    res = SDL_RenderClear(renderer_);

    SDL_Rect r;
    r.w = 16;
    r.h = 16;
    r.x = 16;
    r.y = 16;

    // Set render color to blue ( rect will be rendered in this color )
    res = SDL_SetRenderDrawColor(renderer_, 0, 0, 255, 255);

    // Render rect
    res = SDL_RenderFillRect(renderer_, &r);

    // Render the rect to the screen
    SDL_RenderPresent(renderer_);

    SDL_Delay( 200 );
}