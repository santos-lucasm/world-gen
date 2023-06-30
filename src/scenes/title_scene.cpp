#include "scenes/title_scene.h"
#include "renders/rend_title_scene.h"
//-----------------------------------------------------------------------------
TitleScene::TitleScene(const unsigned int size_w, const unsigned int size_h)
    : IScene(), EventListener("TitleScene")
{
    title_scene_render_ = std::make_unique<RenderTitleScene>(size_w, size_h);
}
//-----------------------------------------------------------------------------
TitleScene::~TitleScene()
{

}
//-----------------------------------------------------------------------------
void TitleScene::Draw()
{
    title_scene_render_->Render();
}
//-----------------------------------------------------------------------------