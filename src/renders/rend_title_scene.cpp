#include "renders/rend_title_scene.h"
//-----------------------------------------------------------------------------
RenderTitleScene::RenderTitleScene(const unsigned int size_w,
    const unsigned int size_h)
    : IRenderer(size_w, size_h)
{

}
//-----------------------------------------------------------------------------
void RenderTitleScene::Render()
{
    SDL_SetRenderDrawColor(renderer_, 0xFD, 0xFD, 0x96, 128);
    ClearWindow();
    SDL_RenderPresent(renderer_);
}
//-----------------------------------------------------------------------------
void RenderTitleScene::ClearWindow()
{
    SDL_RenderClear(renderer_);
}
//-----------------------------------------------------------------------------