#include "renders/rend_title_scene.h"
#include <cassert>
//-----------------------------------------------------------------------------
RenderTitleScene::RenderTitleScene(const unsigned int size_w,
    const unsigned int size_h)
    : IRenderer(size_w, size_h)
{
    texture_ = IMG_LoadTexture(renderer_, "../assets/gb_tilesheet.png");
    assert(texture_);

    // image position in tilesheet
    texture_position_.x = 7 * 16;
    texture_position_.y = 5 * 16;
    texture_position_.w = 3 * 16;
    texture_position_.h = 2 * 16;

    // static image position in screen
    title_position_.x = size_w/2 - (texture_position_.w/2 * 4);
    title_position_.y = size_h/2 - (texture_position_.h/2 * 4);
    title_position_.w = texture_position_.w * 4;
    title_position_.h = texture_position_.h * 4;

    // configure title caption instruction
    text_font_ = TTF_OpenFont("../assets/ttf/abaddon_bold.ttf", 30);
    assert(text_font_);

    text_surface_ = TTF_RenderText_Solid(text_font_, "PRESS SPACE TO CONTINUE...", SDL_Color{0x00, 0x00, 0x00, 0});
    assert(text_surface_);

    text_texture_ = SDL_CreateTextureFromSurface(renderer_, text_surface_);
    assert(text_texture_);

    text_position_.x = size_w/2 - text_surface_->w/2;
    text_position_.y = size_h   - size_h/10;
    text_position_.w = text_surface_->w;
    text_position_.h = text_surface_->h;
    SDL_FreeSurface(text_surface_);
    // SDL_DestroyTexture(text_texture_);
}
//-----------------------------------------------------------------------------
void RenderTitleScene::Render()
{
    SDL_SetRenderDrawColor(renderer_, 0xFD, 0xFD, 0x96, 128);
    ClearWindow();
    SDL_RenderCopy(renderer_, texture_, &texture_position_, &title_position_);
    SDL_RenderCopy(renderer_, text_texture_, NULL, &text_position_);
    SDL_RenderPresent(renderer_);
}
//-----------------------------------------------------------------------------
void RenderTitleScene::ClearWindow()
{
    SDL_RenderClear(renderer_);
}
//-----------------------------------------------------------------------------