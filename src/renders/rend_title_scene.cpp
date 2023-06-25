#include "renders/rend_title_scene.h"
#include <iostream>
//-----------------------------------------------------------------------------
RenderTitleScene::RenderTitleScene(const unsigned int size_w,
    const unsigned int size_h)
    : IRenderer(size_w, size_h)
{
    texture_ = IMG_LoadTexture(renderer_, "../assets/gb_tilesheet.png");
    if(texture_ == NULL)
    {
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        return;
    }

    texture_position_.x = 7 * 16;
    texture_position_.y = 5 * 16;
    texture_position_.w = 3 * 16;
    texture_position_.h = 2 * 16;

    title_position_.x = size_w/2 - (texture_position_.w/2 * 4);
    title_position_.y = size_h/2 - (texture_position_.h/2 * 4);
    title_position_.w = texture_position_.w * 4;
    title_position_.h = texture_position_.h * 4;

}
//-----------------------------------------------------------------------------
void RenderTitleScene::Render()
{
    SDL_SetRenderDrawColor(renderer_, 0xFD, 0xFD, 0x96, 128);
    ClearWindow();
    SDL_RenderCopy(renderer_, texture_, &texture_position_, &title_position_);
    SDL_RenderPresent(renderer_);
}
//-----------------------------------------------------------------------------
void RenderTitleScene::ClearWindow()
{
    SDL_RenderClear(renderer_);
}
//-----------------------------------------------------------------------------