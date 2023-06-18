#ifndef __EV_HANDLER_H__
#define __EV_HANDLER_H__

class Game;
#include <atomic>

extern "C" {
    #include <SDL2/SDL.h>
}

/* TODO: This class should post events upon detection using subscriber and
listener system. This should publish to MessageQueue class, which will store
all events and call*/

/* https://gamedev.stackexchange.com/questions/141636/
event-handling-in-pure-entity-component-systems-is-this-approach-correct */

class EventHandler {
public:
    EventHandler(Game* game);

    void Run();

    bool IsRunning();
private:
    Game* game_;
    std::atomic<bool> is_running_;
    SDL_Event event_;
};

#endif
