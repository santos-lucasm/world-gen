#ifndef __APPLICATION_RUNNING_STATE_H__
#define __APPLICATION_RUNNING_STATE_H__

#include "application/app_state.h"

class ApplicationRunningState : public IApplicationState {
public:
    ApplicationRunningState(Application* app);

    ~ApplicationRunningState();

    void HandleEvents() override;
};

#endif