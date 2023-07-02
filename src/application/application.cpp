#include <cassert>
#include "application/application.h"
#include "scenes/main_scene.h"
#include "scenes/title_scene.h"
#include "events/event_manager.h"
//-----------------------------------------------------------------------------
constexpr unsigned int W_WIDTH = 1024;
constexpr unsigned int W_HEIGHT = 768;
//-----------------------------------------------------------------------------
Application::Application() : is_running_(false)
{
    assert(SDL_Init(SDL_INIT_EVENTS) == 0);
    assert(IMG_Init(IMG_INIT_PNG) != 0);
    assert(TTF_Init() == 0);

    scenes_.push(std::make_shared<TitleScene>(W_WIDTH, W_HEIGHT));
}
//-----------------------------------------------------------------------------
Application::~Application()
{
    while(!scenes_.empty())
    {
        scenes_.pop();
    }
    TTF_Quit();
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
        }
        
        CurrentScene()->Draw();
        SDL_Delay( 1000 / 60 ); // 60fps
    }
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
    static bool pause_button_already_entered_ = false;

    if(sdlevent_.type == SDL_QUIT)
    {
        is_running_ = false;
    }
    else if(sdlevent_.type == SDL_WINDOWEVENT &&
            sdlevent_.window.event == SDL_WINDOWEVENT_CLOSE)
    {
        // TODO: for multiples windows the ev type is SDL_WINDOWEVENT with
        // internal SDL_WINDOWEVENT_CLOSE handle using the window ID
        // FIXME: scenes_.pop() seg fault here because of
        // CurrentScene()->Draw() later in the loop
        is_running_ = false;
    }
    else if(IsKeyPressed(SDLK_ESCAPE))
    {
        // FIXME: pressing ESC before going to main scene miss the first
        // PAUSE_TRIGGERED and the next pressing goes out of pause instead
        pause_button_already_entered_ = !pause_button_already_entered_;
        EventManager::Instance()->NotifyPauseTriggered(Event::PAUSE_TRIGGERED,
            pause_button_already_entered_);
    }
    else if(IsKeyPressed(SDLK_SPACE))
    {
        scenes_.push(std::make_shared<MainScene>(W_WIDTH, W_HEIGHT));
    }
}
//-----------------------------------------------------------------------------
bool Application::IsKeyPressed(SDL_Keycode key)
{
    if(sdlevent_.type == SDL_KEYDOWN && sdlevent_.key.repeat == 0
        && sdlevent_.key.keysym.sym == key)
    {
        return true;
    }
    return false;
}
//-----------------------------------------------------------------------------
