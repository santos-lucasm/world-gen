#ifndef __FSM_H__
#define __FSM_H__

enum class Event;

class Fsm {
public:
    Fsm() {};

    ~Fsm() {};

    virtual void Next(Event e) = 0;
};

#endif