#ifndef __WINDOW_H__
#define __WINDOW_H__

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

/**
 * @brief Main program window to handle graphics
 * 
 * Will handle mouse scroll button and display world terrain upon generation
 */
class Window {
public:
    Window(const unsigned int size_w, const unsigned int size_h);

    ~Window();

    virtual void Update(uint32_t) = 0;

    virtual void Draw() = 0;

    SDL_Window* GetSdlRef();
protected:
    SDL_Window* window_;
};

#endif