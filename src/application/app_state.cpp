#include <cassert>
#include "application/app_state.h"
#include "application/application.h"
//-----------------------------------------------------------------------------
IApplicationState::IApplicationState(Application* app)
    : app_(app)
{
    assert(app_);
}
//-----------------------------------------------------------------------------
IApplicationState::~IApplicationState() = default;
//-----------------------------------------------------------------------------
bool IApplicationState::IsKeyPressed(SDL_Keycode key)
{
    if(Event().type == SDL_KEYDOWN && Event().key.repeat == 0
        && Event().key.keysym.sym == key)
    {
        return true;
    }
    return false;
}
//-----------------------------------------------------------------------------
SDL_Event IApplicationState::Event()
{
    return app_->CurrentEvent();
}
