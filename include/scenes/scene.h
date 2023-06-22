#ifndef __WINDOW_H__
#define __WINDOW_H__

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

enum class Event;

/// @brief Base abstract class for Scenes
/// Will be used in storage with polymorphism
class Scene {
public:
    Scene();

    ~Scene();

    /// @brief Update based in an event
    /// @param e Received event
    virtual void Update(Event e) = 0;

    /// @brief Used to render the scene
    virtual void Draw() = 0;
};

#endif