#include <iostream>
#include "application/running_state.h"
#include "application/application.h"
#include "scenes/main_scene.h"
#include "scenes/title_scene.h"
#include "events/event_manager.h"
#include "application/paused_state.h"
//-----------------------------------------------------------------------------
ApplicationRunningState::ApplicationRunningState(Application* app)
    : IApplicationState(app)
{
    std::cout << "Entered ApplicationRunningState" << std::endl;
    static bool first_run = true;
    if(first_run)
    {
        app_->ChangeScene(std::make_shared<MainScene>(W_WIDTH, W_HEIGHT));
        first_run = false;
    }
}
//-----------------------------------------------------------------------------
ApplicationRunningState::~ApplicationRunningState() = default;
//-----------------------------------------------------------------------------
void ApplicationRunningState::HandleEvents()
{
    if(IsKeyPressed(SDLK_ESCAPE))
    {
        app_->ChangeState(new ApplicationPausedState(app_));
    }
}
//-----------------------------------------------------------------------------