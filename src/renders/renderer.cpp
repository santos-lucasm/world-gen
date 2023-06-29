#include <cassert>
#include "renders/renderer.h"
//-----------------------------------------------------------------------------
SDL_Window* IRenderer::window_ = nullptr;
SDL_Renderer* IRenderer::renderer_ = nullptr;
//-----------------------------------------------------------------------------
IRenderer::IRenderer(const unsigned int size_w, const unsigned int size_h)
{
    InitWindow(size_w, size_h);
    InitRenderer();
}
//-----------------------------------------------------------------------------
IRenderer::~IRenderer()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
}
//-----------------------------------------------------------------------------
void IRenderer::ClearWindow()
{
    SDL_RenderClear(renderer_);
}
//-----------------------------------------------------------------------------
void IRenderer::InitWindow(const unsigned int size_w, const unsigned int size_h)
{
    if(nullptr != window_)
    {
        return;
    }

    window_ = SDL_CreateWindow( "world-gen",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                size_w, size_h, 0);
    assert(window_);
}
//-----------------------------------------------------------------------------
void IRenderer::InitRenderer()
{
    if(nullptr != renderer_)
    {
        return;
    }

    renderer_ = SDL_CreateRenderer(window_, -1,
        SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC );
    assert(renderer_);
}
//-----------------------------------------------------------------------------
