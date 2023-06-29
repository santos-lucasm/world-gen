#include "events/event_manager.h"
#include <iostream>
//TODO: log debug this file
//-----------------------------------------------------------------------------
std::map<Event, std::shared_ptr< std::vector<EventListener*> >>
    EventManager::listeners_ =
{
    { Event::PAUSE_TRIGGERED, std::make_shared<std::vector<EventListener*>>() }
};
//-----------------------------------------------------------------------------
std::shared_ptr<EventManager> EventManager::Instance()
{
    static auto instance = std::make_shared<EventManager>();
    return instance;
}
//-----------------------------------------------------------------------------
void EventManager::Subscribe(Event e, EventListener* listener)
{
    auto [subscribed, pos] = AlreadySubscribed(e, listener);
    if(false == subscribed)
    {
        EventCurrentListeners(e)->push_back(listener);
        std::cout << listener->Id() << " subscribed to event "
            << static_cast<int>(e) << std::endl;
    }
}
//-----------------------------------------------------------------------------
void EventManager::Unsubscribe(Event e, EventListener* listener)
{
    auto [subscribed, pos] = AlreadySubscribed(e, listener);
    if(true == subscribed)
    {
        auto listeners = EventCurrentListeners(e);
        listeners->erase(pos);

        std::cout << listener->Id() << " unsubscribed from event "
            << static_cast<int>(e) << std::endl;
    }
}
//-----------------------------------------------------------------------------
void EventManager::NotifyPauseTriggered(Event e, bool entered_pause_mode)
{
    auto listeners = EventCurrentListeners(e);
    for(auto listener : *listeners)
    {
        std::cout << listener->Id() << " notified!" << std::endl;;
        /// TODO: push this function into a notifications queue to be consumed
        listener->OnPause(entered_pause_mode);
    }
}
//-----------------------------------------------------------------------------
std::tuple<bool, std::vector<EventListener*>::iterator>
    EventManager::AlreadySubscribed(Event e, EventListener* listener)
{
    auto l = EventCurrentListeners(e);
    for(auto it = l->begin(); it != l->end(); it++)
    {
        if((*it)->Id() == listener->Id())
        {
            return {true, it};
        }
    }
    return {false, l->end()};
}
//-----------------------------------------------------------------------------
std::shared_ptr<std::vector<EventListener*>>
    EventManager::EventCurrentListeners(Event e)
{
    //TODO: handle unknown event
    return listeners_[e];
}
//-----------------------------------------------------------------------------
