#ifndef __FSM_H__
#define __FSM_H__

#include "fsm/event_types.h"

class Fsm {
public:
    Fsm() {};

    ~Fsm() {};

    virtual void Update(Event e) = 0;
};

#endif