#ifndef __APPLICATION_TITLE_STATE_H__
#define __APPLICATION_TITLE_STATE_H__

#include "application/app_state.h"

class ApplicationTitleState : public IApplicationState {
public:
    ApplicationTitleState(Application* app);

    ~ApplicationTitleState();

    void HandleEvents() override;
};

#endif