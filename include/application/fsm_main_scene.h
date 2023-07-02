#ifndef __FSM_MAIN_SCENE_H__
#define __FSM_MAIN_SCENE_H__

#include "application/fsm.h"

enum class Event;

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

    void Set(MainSceneState state);

    /// @brief Update fsm according the received event
    /// @param e Event received
    void Next(Event e);

    /// @brief Get currente fsm state
    /// @return Current state
    MainSceneState State();
private:
    MainSceneState state_;
};

#endif