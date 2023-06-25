#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include <map>
#include <vector>
#include <memory>
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
    /// @brief Singleton pattern, app dont have access to class constructor
    /// @return EventManager reference 
    static std::shared_ptr<EventManager> Instance();

    /// @brief Subscribe a listener to an event, if it's already subscribed
    /// nothing happens
    /// @param e Event to subscribe
    /// @param listener Listener reference to bound to the event
    void Subscribe(Event e, EventListener* listener);

    /// @brief Unsubscribe a listener to an event, if the listener is not
    /// subscribed to the event, nothing happens
    /// @param e Event to unsubscribe
    /// @param listener Listener reference to remove from event subscribers
    void Unsubscribe(Event e, EventListener* listener);

    /// @brief Called wherever the system detects enter or exit to pause mode
    /// @param e PAUSE_TRIGGERED event 
    /// @param entered_pause_mode true for entering pause, false for resuming
    void NotifyPauseTriggered(Event e, bool entered_pause_mode);
private:
    /// @brief Verifies if a listener is already subscriber of an event
    /// @param e Event to verify listener
    /// @param listener Listener to be found in event subscribers
    /// @return First return indicates if it's subscribed or not. If it's
    /// subscribed, second return is the iterator position in the array. If
    /// it's not subscribed, the second return point to EventListener vector
    /// end()
    std::tuple<bool, std::vector<EventListener*>::iterator>
        AlreadySubscribed(Event e, EventListener* listener);

    /// @brief Returns vector of listeners of an event
    /// @param e Event to return the listeners
    /// @return Vector of EventListeners for this event, it the Event is
    /// invalid, returns nullptr
    static std::shared_ptr<std::vector<EventListener*>>
        EventCurrentListeners(Event e);
private:
    /// @brief Stores singleton instance of the class
    static std::shared_ptr<EventManager> instance_;

    /// @brief Maps events to listeners container 
    static std::map<Event,
        std::shared_ptr< std::vector<EventListener*> >> listeners_;
};

#endif