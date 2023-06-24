#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include <map>
#include <vector>
#include "event_listener.h"
#include "events/event_types.h"

/// @brief Handles events
/// One notify for every event, i.e NotifyNewScene(EVENT_DATA), and
/// one listener array for each specific event.
/// Button presses are NOT events, they're inputs that need
/// to be converted to real events that will call specific Notifies.
class EventManager
{
public:
    void Subscribe(Event e, EventListener* listener);
    void Unsubscribe(Event e, EventListener* listener);
    void NotifyPauseTriggered(Event e, bool entered_pause_mode);
private:
    std::vector<EventListener*> pause_triggered_listeners_;
};

#endif