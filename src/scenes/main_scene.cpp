#include <thread>
#include "scenes/main_scene.h"
#include "scenes/main_scene/world.h"
#include "renders/rend_main_scene.h"
#include "fsm/fsm_main_scene.h"
#include "events/event_types.h"
//-----------------------------------------------------------------------------
MainScene::MainScene(const unsigned int size_w, const unsigned int size_h)
    : Scene(), EventListener("MainScene"), x_blocks_(size_w/16), y_blocks_(size_h/16)
{
    w_render_ = std::make_unique<RenderMainScene>(size_w, size_h);
    world_ = std::make_shared<World>(x_blocks_, y_blocks_);
    fsm_ = std::make_unique<FsmMainScene>();
    fsm_->Set(MainSceneState::RUNNING);

    auto seed1 = std::thread(&World::ProceduralGeneration, world_.get(), 0, 0);
    auto seed2 = std::thread(&World::ProceduralGeneration, world_.get(), x_blocks_-1, 0);
    auto seed3 = std::thread(&World::ProceduralGeneration, world_.get(), x_blocks_/2, y_blocks_-1);

    seed1.detach();
    seed2.detach();
    seed3.detach();

}
//-----------------------------------------------------------------------------
MainScene::~MainScene()
{

}
//-----------------------------------------------------------------------------
void MainScene::Draw()
{
    w_render_->Render(world_);
}
//-----------------------------------------------------------------------------
void MainScene::OnPause(bool entered_pause_mode)
{
    fsm_->Next(Event::PAUSE_TRIGGERED);

    if(entered_pause_mode)
    {
        world_->Pause();
    }
    else
    {
        world_->Play();
    }
}
//-----------------------------------------------------------------------------
