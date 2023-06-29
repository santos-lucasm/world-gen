#ifndef __EVENT_LISTENER_H__
#define __EVENT_LISTENER_H__

#include <iostream>
#include <string>

/// @brief EventListener base class
/// Components and scenes that need to react to some events should inherit
/// from this class and subscribe to the relatable events
class EventListener
{
public:
    /// @brief Sets listener string id
    /// @param id event listener id 
    EventListener(const std::string id) : id_(id) {}

    /// @brief Used to get access to listener id
    /// @return listener string id
    std::string Id() { return id_; }

    /// @brief Called wherever a PAUSE_TRIGGERED event is sent and some
    /// derivate class subscribed to the event and haven't implemented
    /// OnPause override function
    /// @param entered_pause_mode true if entering pause mode, false if
    /// resuming
    virtual void OnPause(bool entered_pause_mode)
        { std::cout << "Missing OnPause definition!" << std::endl; };
private:
    /// @brief identifier used to verify if listener is already subscribed
    /// to an event
    std::string id_;
};

#endif