#include "fsm/fsm_main_w.h"
//-----------------------------------------------------------------------------
FsmMainWindow::FsmMainWindow() : state_(MainWindowState::IDLE)
{

}
//-----------------------------------------------------------------------------
FsmMainWindow::~FsmMainWindow()
{
    state_ = MainWindowState::IDLE;
}
//-----------------------------------------------------------------------------
void FsmMainWindow::Update(Event e)
{
    switch(e)
    {
        case Event::START_MAINWINDOW_EXEC:
            if(state_ == MainWindowState::IDLE)
            {
                state_ = MainWindowState::RUNNING;
            }
            break;
        case Event::PAUSE_PROCEDURAL_GENERATION:
            if(state_ == MainWindowState::RUNNING)
            {
                state_ = MainWindowState::PAUSED;
            }
            break;
        case Event::RESUME_PROCEDURAL_GENERATION:
            if(state_ == MainWindowState::PAUSED)
            {
                state_ = MainWindowState::RUNNING;
            }
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------
MainWindowState FsmMainWindow::State()
{
    return state_;
}
//-----------------------------------------------------------------------------
