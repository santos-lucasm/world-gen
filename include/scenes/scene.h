#ifndef __WINDOW_H__
#define __WINDOW_H__

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

enum class Event;

/**
 * @brief Main program window to handle graphics
 * 
 * Will handle mouse scroll button and display world terrain upon generation
 */
class Scene {
public:
    Scene(const unsigned int size_w, const unsigned int size_h);

    ~Scene();

    virtual void Update(Event) = 0;

    virtual void Draw() = 0;

    SDL_Window* GetSdlRef();
protected:
    SDL_Window* window_;
};

#endif