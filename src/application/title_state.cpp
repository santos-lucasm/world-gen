#include <iostream>
#include "application/title_state.h"
#include "application/application.h"
#include "application/running_state.h"
#include "scenes/title_scene.h"
//-----------------------------------------------------------------------------
ApplicationTitleState::ApplicationTitleState(Application* app)
    : IApplicationState(app)
{
    std::cout << "Entered ApplicationTitleState" << std::endl;
    app_->ChangeScene(std::make_shared<TitleScene>(W_WIDTH, W_HEIGHT));
}
//-----------------------------------------------------------------------------
ApplicationTitleState::~ApplicationTitleState() = default;
//-----------------------------------------------------------------------------
void ApplicationTitleState::HandleEvents()
{
    if(IsKeyPressed(SDLK_SPACE))
    {
        app_->ChangeState(new ApplicationRunningState(app_));
    }
}
//-----------------------------------------------------------------------------