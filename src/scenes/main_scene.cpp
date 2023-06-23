#include <thread>
#include "scenes/main_scene.h"
#include "scenes/main_scene/world.h"
#include "renders/rend_main_scene.h"
#include "fsm/fsm_main_scene.h"
#include "fsm/event_types.h"
//-----------------------------------------------------------------------------
MainScene::MainScene(const unsigned int size_w, const unsigned int size_h)
    : Scene(), x_blocks_(size_w/16), y_blocks_(size_h/16)
{
    w_render_ = std::make_unique<RenderMainScene>(size_w, size_h);
    fsm_ = std::make_unique<FsmMainScene>();

    world_ = std::make_shared<World>(x_blocks_, y_blocks_);

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
void MainScene::Update(Event e)
{
    fsm_->Update(e);
    auto st = fsm_->State();

    if(st == MainSceneState::PAUSED)
    {
        world_->Pause();
    }
    else if(st == MainSceneState::RUNNING && e == Event::RESUME_PROCEDURAL_GENERATION)
    {
        world_->Play();
    }
}
//-----------------------------------------------------------------------------
void MainScene::Draw()
{
    w_render_->Render(world_);
}
//-----------------------------------------------------------------------------
