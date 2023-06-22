#ifndef __FSM_MAIN_SCENE_H__
#define __FSM_MAIN_SCENE_H__

#include "fsm/fsm.h"

/// @brief MainScene states
enum class MainSceneState
{
    IDLE, // initial state
    RUNNING, // procedural gen running
    PAUSED, // procedural gen paused
};

/// @brief State machine for MainScene
class FsmMainScene : public Fsm {
public:
    FsmMainScene();

    ~FsmMainScene();

    /// @brief Update fsm according the received event
    /// @param e Event received
    void Update(Event e);

    /// @brief Get currente fsm state
    /// @return Current state
    MainSceneState State();
private:
    MainSceneState state_;
};

#endif