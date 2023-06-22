#ifndef __FSM_MAIN_W_H__
#define __FSM_MAIN_W_H__

#include "fsm/fsm.h"

enum class MainWindowState
{
    IDLE, // initial state
    RUNNING, // procedural gen running
    PAUSED, // procedural gen paused
};

class FsmMainWindow {
public:
    FsmMainWindow();

    ~FsmMainWindow();

    void Update(Event e);

    MainWindowState State();
private:
    MainWindowState state_;
};

#endif