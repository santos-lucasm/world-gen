#ifndef __EVENT_LISTENER_H__
#define __EVENT_LISTENER_H__

#include <iostream>
#include <string>

class EventListener
{
public:
    EventListener(const std::string id) : id_(id) {}
    ~EventListener() {}
    std::string Id() { return id_; }
    virtual void OnPause(bool entered_pause_mode) { std::cout << "Pause!" << std::endl; };
private:
    std::string id_;
};

#endif