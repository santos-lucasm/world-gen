#include "scenes/main_scene/world.h"
#include "renders/rend_main_scene.h"

RenderMainScene::RenderMainScene(SDL_Window* window)
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
        {terrain_t::NONE,  {255, 255, 255}}, // white
        {terrain_t::WATER, {0, 0, 255}}, // blue
        {terrain_t::GROUND, {0, 255, 0}}, // green
        {terrain_t::MOUNTAIN, {150, 75, 0}}, //brown
    };
}

RenderMainScene::~RenderMainScene()
{
    SDL_DestroyRenderer(sdl_renderer_);
}

void RenderMainScene::Render(std::shared_ptr<World> world)
{
    // Set render color to red ( background will be rendered in this color )
    auto [x, y] = world->GetWorldSize();
    
    // set bg to black
    SDL_SetRenderDrawColor(sdl_renderer_, 0, 0, 0, 0);

    // clears the screen
    SDL_RenderClear(sdl_renderer_);

    //for now, print x rectangles using world format
    SDL_Rect rect;
    rect.w = 16;
    rect.h = 16;

    // terrain_t current;

    for(unsigned int j = 0; j < y; ++j)
    {
        for(unsigned int i = 0; i < x; ++i)
        {
            auto current = world->GetTerrain(i, j);

            if(current == terrain_t::NONE) continue;

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