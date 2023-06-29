#include "renders/rend_title_scene.h"
#include <cassert>
//-----------------------------------------------------------------------------
RenderTitleScene::RenderTitleScene(const unsigned int size_w,
    const unsigned int size_h)
    : IRenderer(size_w, size_h)
{
    SetLogo(size_w, size_h);
    SetCaption(size_w, size_h);
}
//-----------------------------------------------------------------------------
RenderTitleScene::~RenderTitleScene()
{
    SDL_DestroyTexture(caption_texture_);
    SDL_DestroyTexture(logo_texture_);
    TTF_CloseFont(caption_font_);
}
//-----------------------------------------------------------------------------
void RenderTitleScene::Render()
{
    SDL_SetRenderDrawColor(renderer_, 0xFD, 0xFD, 0x96, 128);
    ClearWindow();
    SDL_RenderCopy(renderer_, logo_texture_, &logo_texture_position_,
        &logo_screen_position_);
    SDL_RenderCopy(renderer_, caption_texture_, NULL, &caption_position_);
    SDL_RenderPresent(renderer_);
}
//-----------------------------------------------------------------------------
void RenderTitleScene::SetLogo(const unsigned int size_w,
    const unsigned int size_h)
{
    // load title sheet into texture
    logo_texture_ = IMG_LoadTexture(renderer_, "../assets/gb_tilesheet.png");
    assert(logo_texture_);

    // retrieve logo place inside loaded texture tilesheet
    logo_texture_position_.x = 7 * 16;
    logo_texture_position_.y = 5 * 16;
    logo_texture_position_.w = 3 * 16;
    logo_texture_position_.h = 2 * 16;

    // static image position in screen
    logo_screen_position_.x = size_w/2 - (logo_texture_position_.w/2 * 4);
    logo_screen_position_.y = size_h/2 - (logo_texture_position_.h/2 * 4);
    logo_screen_position_.w = logo_texture_position_.w * 4;
    logo_screen_position_.h = logo_texture_position_.h * 4;
}
//-----------------------------------------------------------------------------
void RenderTitleScene::SetCaption(const unsigned int size_w,
    const unsigned int size_h)
{
    // init ttf font
    caption_font_ = TTF_OpenFont("../assets/ttf/abaddon_bold.ttf", 30);
    assert(caption_font_);

    SDL_Surface* caption_surface_ = TTF_RenderText_Solid(caption_font_,
        "PRESS SPACE TO CONTINUE...", SDL_Color{0x00, 0x00, 0x00, 0});
    assert(caption_surface_);

    caption_texture_ =
        SDL_CreateTextureFromSurface(renderer_, caption_surface_);
    assert(caption_texture_);

    caption_position_.x = size_w/2 - caption_surface_->w/2;
    caption_position_.y = size_h   - size_h/10;
    caption_position_.w = caption_surface_->w;
    caption_position_.h = caption_surface_->h;
    SDL_FreeSurface(caption_surface_);
}
//-----------------------------------------------------------------------------