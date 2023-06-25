#include "scenes/main_scene/world.h"
#include "renders/rend_main_scene.h"
//-----------------------------------------------------------------------------
std::map<terrain_t, std::tuple<uint8_t, uint8_t, uint8_t>>
    RenderMainScene::color_map_ =
        std::map<terrain_t, std::tuple<uint8_t, uint8_t, uint8_t>> {
            {terrain_t::NONE,       {255, 255, 255}},   // white
            {terrain_t::WATER,      {204, 204, 204}},   // #CCCCCC
            {terrain_t::GROUND,     {128, 128, 128}},   // #808080
            {terrain_t::MOUNTAIN,   {64, 64, 64}},      // #404040 #363636 #171717
        };
//-----------------------------------------------------------------------------
RenderMainScene::RenderMainScene(const unsigned int size_w, const unsigned int size_h)
    : sdl_renderer_(NULL)
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
RenderMainScene::~RenderMainScene()
{
    SDL_DestroyRenderer(sdl_renderer_);
    SDL_DestroyWindow(window_);
}
//-----------------------------------------------------------------------------
void RenderMainScene::Render(std::shared_ptr<World> world)
{
    ClearWindow();

    // Rect that will be used to render world tiles
    SDL_Rect rect;
    rect.w = 16;
    rect.h = 16;

    // Iterate over world size rendering itf
    auto [x, y] = world->GetWorldSize();
    for(unsigned int j = 0; j < y; ++j)
    {
        for(unsigned int i = 0; i < x; ++i)
        {
            auto current = world->GetTerrain(i, j);

            if(current == terrain_t::NONE) continue;

            SDL_SetRenderDrawColor(sdl_renderer_,
                std::get<0>(color_map_[current]),
                std::get<1>(color_map_[current]),
                std::get<2>(color_map_[current]), 128);

            // Update rect world relative position
            rect.x = i*16;
            rect.y = j*16;

            SDL_RenderFillRect(sdl_renderer_, &rect);
        }
    }
    // Render the rect to the screen
    SDL_RenderPresent(sdl_renderer_);
}
//-----------------------------------------------------------------------------
void RenderMainScene::ClearWindow()
{
    SDL_SetRenderDrawColor(sdl_renderer_, 0, 0, 0, 0);
    SDL_RenderClear(sdl_renderer_);
}
//-----------------------------------------------------------------------------
