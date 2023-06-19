#include "windows/main_w/world.h"
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

    color_map_ = std::map<terrain_t, std::tuple<uint8_t, uint8_t, uint8_t>> {
        {terrain_t::NONE,  {255, 255, 255}},
        {terrain_t::WATER, {0, 0, 255}},
        {terrain_t::GROUND, {0, 255, 0}},
        {terrain_t::MOUNTAIN, {150, 75, 0}},
    };
}

RenderMainWindow::~RenderMainWindow()
{
    SDL_DestroyRenderer(sdl_renderer_);
}

void RenderMainWindow::Render(std::shared_ptr<World> world)
{
    // Set render color to red ( background will be rendered in this color )
    auto [x, y] = world->GetWorldSize();
    
    // set bg to white
    SDL_SetRenderDrawColor(sdl_renderer_, 0, 0, 0, 0);

    // clears the screen
    SDL_RenderClear(sdl_renderer_);

    //for now, print x rectangles using world format
    SDL_Rect rect;
    rect.w = 16;
    rect.h = 16;

    // terrain_t current;

    for(auto j = 0; j < y; ++j)
    {
        for(auto i = 0; i < x; ++i)
        {
            auto current = world->GetTerrain(i, j);

            SDL_SetRenderDrawColor(sdl_renderer_,
                std::get<0>(color_map_[current]),
                std::get<1>(color_map_[current]),
                std::get<2>(color_map_[current]), 255);

            // update square position
            rect.x = i*16;
            rect.y = j*16;

            // Render rect
            SDL_RenderFillRect(sdl_renderer_, &rect);
        }
    }
    // Render the rect to the screen
    SDL_RenderPresent(sdl_renderer_);
}