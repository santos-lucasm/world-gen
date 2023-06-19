#include "windows/main_w.h"
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
