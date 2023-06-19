#include "windows/main_w.h"
#include "windows/main_w/world.h"
#include "renders/rend_main_w.h"
//-----------------------------------------------------------------------------
MainWindow::MainWindow(const unsigned int size_w, const unsigned int size_h)
    : Window(size_w, size_h)
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

    world_ = std::make_shared<World>(size_w/16, size_h/16);
    world_gen_thread_ = std::thread(&World::ProceduralGeneration, world_.get());
}
//-----------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    // activate to not let user close window before world generation is over
    // world_gen_thread_.join();
}
//-----------------------------------------------------------------------------
void MainWindow::Update()
{

}
//-----------------------------------------------------------------------------
void MainWindow::Draw()
{
    w_render_->Render(world_);
}
//-----------------------------------------------------------------------------
