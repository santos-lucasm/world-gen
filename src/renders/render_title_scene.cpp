#include "renders/rend_title_scene.h"
//-----------------------------------------------------------------------------
RenderTitleScene::RenderTitleScene(const unsigned int size_w, const unsigned int size_h)
{
    window_ = SDL_CreateWindow( "world-gen",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                size_w, size_h, 0);
    if(!window_)
    {
        //TODO: handle err
    }

    // triggers the program that controls your graphics hardware and sets flags
    // creates a renderer to render our images
    sdl_renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if(!sdl_renderer_)
    {
        //TODO: handle err
        return;
    }
}
//-----------------------------------------------------------------------------
RenderTitleScene::~RenderTitleScene()
{
    SDL_DestroyRenderer(sdl_renderer_);
    SDL_DestroyWindow(window_);
}
//-----------------------------------------------------------------------------
void RenderTitleScene::Render()
{
    SDL_SetRenderDrawColor(sdl_renderer_, 0xFD, 0xFD, 0x96, 128);
    ClearWindow();
    SDL_RenderPresent(sdl_renderer_);
}
//-----------------------------------------------------------------------------
void RenderTitleScene::ClearWindow()
{
    SDL_RenderClear(sdl_renderer_);
}
//-----------------------------------------------------------------------------