#include "scenes/main_scene/world.h"
#include "renders/rend_main_scene.h"
//-----------------------------------------------------------------------------
std::map<terrain_t, std::tuple<uint8_t, uint8_t, uint8_t>>
    RenderMainScene::color_map_ =
        std::map<terrain_t, std::tuple<uint8_t, uint8_t, uint8_t>> {
            {terrain_t::NONE,       {255, 255, 255}},
            {terrain_t::WATER,      {0xCC, 0xCC, 0xCC}},
            {terrain_t::GROUND,     {0x80, 0x80, 0x80}},
            {terrain_t::HILL,       {0x40, 0x40, 0x40}},
            {terrain_t::MOUNTAIN,   {0x17, 0x17, 0x17}},
        };
//-----------------------------------------------------------------------------
RenderMainScene::RenderMainScene(const unsigned int size_w, const unsigned int size_h)
    : IRenderer(size_w, size_h)
{

}
//-----------------------------------------------------------------------------
void RenderMainScene::Render(std::shared_ptr<World> world)
{
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 0);
    ClearWindow();

    // Rect that will be used to render world tiles
    static SDL_Rect rect;
    rect.w = 16;
    rect.h = 16;

    // Iterate over world size rendering itf
    auto [x, y] = world->GetWorldSize();
    for(unsigned int j = 0; j < y; ++j)
    {
        for(unsigned int i = 0; i < x; ++i)
        {
            auto title_terrain = world->GetTerrain(i, j);

            if(terrain_t::NONE == title_terrain)
            {
                continue;
            }

            rect.x = i*16;
            rect.y = j*16;

            SDL_SetRenderDrawColor(renderer_,
                std::get<0>(color_map_[title_terrain]),
                std::get<1>(color_map_[title_terrain]),
                std::get<2>(color_map_[title_terrain]), 128);
            SDL_RenderFillRect(renderer_, &rect);
        }
    }
    // Render the rect to the screen
    SDL_RenderPresent(renderer_);
}
//-----------------------------------------------------------------------------
