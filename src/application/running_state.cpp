#include <iostream>
#include "application/running_state.h"
#include "application/application.h"
#include "scenes/main_scene.h"
#include "scenes/title_scene.h"
#include "events/event_manager.h"
//-----------------------------------------------------------------------------
ApplicationRunningState::ApplicationRunningState(Application* app)
    : IApplicationState(app)
{
    std::cout << "Entered ApplicationRunningState" << std::endl;
    app_->ChangeScene(std::make_shared<MainScene>(W_WIDTH, W_HEIGHT));
}
//-----------------------------------------------------------------------------
ApplicationRunningState::~ApplicationRunningState() = default;
//-----------------------------------------------------------------------------
void ApplicationRunningState::HandleEvents()
{
    if(IsKeyPressed(SDLK_ESCAPE))
    {
        EventManager::Instance()->NotifyPauseTriggered(
            Event::PAUSE_TRIGGERED, true);
    }
}
//-----------------------------------------------------------------------------