#include "windows/main_w.h"
#include "windows/main_w/world.h"
#include "renders/rend_main_w.h"
#include "fsm/fsm_main_w.h"
//-----------------------------------------------------------------------------
MainWindow::MainWindow(const unsigned int size_w, const unsigned int size_h)
    : Window(size_w, size_h), x_blocks_(size_w/16), y_blocks_(size_h/16)
{
    window_ = SDL_CreateWindow( "world-gen",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                size_w, size_h, 0);
    if(!window_)
    {
        //TODO: handle err
    }

    w_render_ = std::make_unique<RenderMainWindow>(GetSdlRef());
    fsm_ = std::make_unique<FsmMainWindow>();

    world_ = std::make_shared<World>(x_blocks_, y_blocks_);

    auto seed1 = std::thread(&World::ProceduralGeneration, world_.get(), 0, 0);
    auto seed2 = std::thread(&World::ProceduralGeneration, world_.get(), x_blocks_-1, y_blocks_-1);

    seed1.detach();
    seed2.detach();
}
//-----------------------------------------------------------------------------
MainWindow::~MainWindow()
{

}
//-----------------------------------------------------------------------------
void MainWindow::Update(Event e)
{
    fsm_->Update(e);
    auto st = fsm_->State();

    if(st == MainWindowState::PAUSED)
    {
        world_->Pause();
    }
    else if(st == MainWindowState::RUNNING && e == Event::RESUME_PROCEDURAL_GENERATION)
    {
        world_->Play();
    }
}
//-----------------------------------------------------------------------------
void MainWindow::Draw()
{
    w_render_->Render(world_);
}
//-----------------------------------------------------------------------------
