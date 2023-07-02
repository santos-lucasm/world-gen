#ifndef __APPLICATION_PAUSED_STATE_H__
#define __APPLICATION_PAUSED_STATE_H__

#include "application/app_state.h"

class ApplicationPausedState : public IApplicationState {
public:
    ApplicationPausedState(Application* app);

    ~ApplicationPausedState();

    void HandleEvents() override;
};

#endif