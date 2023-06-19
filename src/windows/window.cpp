#include "windows/window.h"
#include <iostream>
//-----------------------------------------------------------------------------
Window::Window(const unsigned int size_w, const unsigned int size_h)
{

}
//-----------------------------------------------------------------------------
Window::~Window()
{
    SDL_DestroyWindow(window_);
    SDL_Quit();
}
//-----------------------------------------------------------------------------
SDL_Window* Window::GetSdlRef()
{
    return window_;
}
//-----------------------------------------------------------------------------
