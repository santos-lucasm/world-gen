#include "fsm/fsm_main_scene.h"
//-----------------------------------------------------------------------------
FsmMainScene::FsmMainScene() : state_(MainSceneState::IDLE)
{

}
//-----------------------------------------------------------------------------
FsmMainScene::~FsmMainScene()
{
    state_ = MainSceneState::IDLE;
}
//-----------------------------------------------------------------------------
void FsmMainScene::Update(Event e)
{
    switch(e)
    {
        case Event::START_MAINSCENE_EXEC:
            if(state_ == MainSceneState::IDLE)
            {
                state_ = MainSceneState::RUNNING;
            }
            break;
        case Event::PAUSE_PROCEDURAL_GENERATION:
            if(state_ == MainSceneState::RUNNING)
            {
                state_ = MainSceneState::PAUSED;
            }
            break;
        case Event::RESUME_PROCEDURAL_GENERATION:
            if(state_ == MainSceneState::PAUSED)
            {
                state_ = MainSceneState::RUNNING;
            }
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------
MainSceneState FsmMainScene::State()
{
    return state_;
}
//-----------------------------------------------------------------------------
