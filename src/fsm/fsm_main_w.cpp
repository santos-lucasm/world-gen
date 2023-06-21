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
        case Event::PAUSE:
            if(state_ == MainWindowState::RUNNING)
            {
                state_ = MainWindowState::PAUSED;
            }
            break;
        case Event::RESUME:
            if(state_ == MainWindowState::PAUSED)
            {
                state_ = MainWindowState::RESUMING;
            }
            else if(state_ == MainWindowState::RESUMING)
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
