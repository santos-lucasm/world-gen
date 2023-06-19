#include "windows/main_w.h"
#include "windows/main_w/world.h"
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

    world_ = std::make_unique<World>(size_w/16, size_h/16);
    world_->ProceduralGeneration();
    world_->Draw();
}
//-----------------------------------------------------------------------------
MainWindow::~MainWindow()
{

}
//-----------------------------------------------------------------------------
void MainWindow::Update()
{

}
//-----------------------------------------------------------------------------
