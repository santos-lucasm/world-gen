#include "fsm/fsm_main_scene.h"
#include "events/event_types.h"
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
void FsmMainScene::Set(MainSceneState state)
{
    state_ = state;
}
//-----------------------------------------------------------------------------
void FsmMainScene::Next(Event e)
{
    switch(e)
    {
        case Event::PAUSE_TRIGGERED:
            if(state_ == MainSceneState::RUNNING)
            {
                state_ = MainSceneState::PAUSED;
            }
            else
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
