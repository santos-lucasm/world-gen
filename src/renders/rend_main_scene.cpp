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
    : IRenderer(size_w, size_h)
{

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

            SDL_SetRenderDrawColor(renderer_,
                std::get<0>(color_map_[current]),
                std::get<1>(color_map_[current]),
                std::get<2>(color_map_[current]), 128);

            // Update rect world relative position
            rect.x = i*16;
            rect.y = j*16;

            SDL_RenderFillRect(renderer_, &rect);
        }
    }
    // Render the rect to the screen
    SDL_RenderPresent(renderer_);
}
//-----------------------------------------------------------------------------
void RenderMainScene::ClearWindow()
{
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0);
    SDL_RenderClear(renderer_);
}
//-----------------------------------------------------------------------------
