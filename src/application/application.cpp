#include <cassert>
#include "application/application.h"
#include "application/title_state.h"
#include "scenes/main_scene.h"
#include "scenes/title_scene.h"
#include "events/event_manager.h"
//-----------------------------------------------------------------------------
Application::Application() : is_running_(false)
{
    assert(SDL_Init(SDL_INIT_EVENTS) == 0);
    assert(IMG_Init(IMG_INIT_PNG) != 0);
    assert(TTF_Init() == 0);

    state_ = new ApplicationTitleState(this);
}
//-----------------------------------------------------------------------------
Application::~Application()
{
    while(!scenes_.empty())
    {
        scenes_.pop();
    }
    delete state_;
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
//-----------------------------------------------------------------------------
void Application::Run()
{
    is_running_ = true;

    while(IsRunning())
    {
        while (SDL_PollEvent(&sdlevent_))
        {
            HandleEvents();
            state_->HandleEvents();
        }
        
        CurrentScene()->Draw();
        SDL_Delay( 1000 / 60 ); // 60fps
    }
}
//-----------------------------------------------------------------------------
SDL_Event Application::CurrentEvent()
{
    return sdlevent_;
}
//-----------------------------------------------------------------------------
void Application::ChangeScene(std::shared_ptr<IScene> scene)
{
    scenes_.push(scene);
}
//-----------------------------------------------------------------------------
void Application::ChangeState(IApplicationState* state)
{
    delete state_;
    state_ = state;
}
//-----------------------------------------------------------------------------
std::shared_ptr<IScene> Application::CurrentScene()
{
    return scenes_.top();
}
//-----------------------------------------------------------------------------
bool Application::IsRunning()
{
    return is_running_;
}
//-----------------------------------------------------------------------------
void Application::HandleEvents()
{
    //https://stackoverflow.com/questions/24727184/zooming-an-image-while-keeping-it-centered-in-sdl2
    // static bool pause_button_already_entered_ = false;

    if(sdlevent_.type == SDL_QUIT)
    {
        is_running_ = false;
    }
    // else if(sdlevent_.type == SDL_WINDOWEVENT &&
    //         sdlevent_.window.event == SDL_WINDOWEVENT_CLOSE)
    // {
    //     // TODO: for multiples windows the ev type is SDL_WINDOWEVENT with
    //     // internal SDL_WINDOWEVENT_CLOSE handle using the window ID
    //     // FIXME: scenes_.pop() seg fault here because of
    //     // CurrentScene()->Draw() later in the loop
    //     is_running_ = false;
    // }
}
//-----------------------------------------------------------------------------
