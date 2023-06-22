#include "scenes/scene.h"
#include <iostream>
//-----------------------------------------------------------------------------
Scene::Scene(const unsigned int size_w, const unsigned int size_h)
{

}
//-----------------------------------------------------------------------------
Scene::~Scene()
{
    SDL_DestroyWindow(window_);
    SDL_Quit();
}
//-----------------------------------------------------------------------------
SDL_Window* Scene::GetSdlRef()
{
    return window_;
}
//-----------------------------------------------------------------------------
