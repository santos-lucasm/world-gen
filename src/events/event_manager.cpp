#include "events/event_manager.h"
//-----------------------------------------------------------------------------
void EventManager::Subscribe(Event e, EventListener* listener)
{
    // TODO: map events to vector
    switch(e)
    {
        case Event::PAUSE_TRIGGERED:
            pause_triggered_listeners_.push_back(listener);
            break;
        default:
            break;

    }
}
//-----------------------------------------------------------------------------
void EventManager::Unsubscribe(Event e, EventListener* listener)
{
    // TODO: map events to vector
    switch(e)
    {
        case Event::PAUSE_TRIGGERED:
            for(auto it = pause_triggered_listeners_.begin();
                it != pause_triggered_listeners_.end(); it++)
            {
                if((*it)->Id() == listener->Id())
                {
                    pause_triggered_listeners_.erase(it);
                    break;
                }
            }
        default:
            break;

    }
}
//-----------------------------------------------------------------------------
void EventManager::NotifyPauseTriggered(Event e, bool entered_pause_mode)
{
    for(auto listener : pause_triggered_listeners_)
    {
        listener->OnPause(entered_pause_mode);
    }
}
//-----------------------------------------------------------------------------
