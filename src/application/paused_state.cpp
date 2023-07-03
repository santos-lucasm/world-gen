#include <iostream>
#include "application/running_state.h"
#include "application/paused_state.h"
#include "application/application.h"
#include "scenes/main_scene.h"
#include "scenes/title_scene.h"
#include "events/event_manager.h"
//-----------------------------------------------------------------------------
ApplicationPausedState::ApplicationPausedState(Application* app)
    : IApplicationState(app)
{
    std::cout << "Entered ApplicationPausedState" << std::endl;
    EventManager::Instance()->NotifyPauseTriggered(
        Event::PAUSE_TRIGGERED, true);
}
//-----------------------------------------------------------------------------
ApplicationPausedState::~ApplicationPausedState() = default;
//-----------------------------------------------------------------------------
void ApplicationPausedState::HandleEvents()
{
    if(IsKeyPressed(SDLK_ESCAPE))
    {
        EventManager::Instance()->NotifyPauseTriggered(
            Event::PAUSE_TRIGGERED, false);
        app_->ChangeState(new ApplicationRunningState(app_));
    }
}
//-----------------------------------------------------------------------------