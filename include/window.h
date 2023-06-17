#ifndef __WINDOW_H__
#define __WINDOW_H__

extern "C" {
    #include <SDL2/SDL.h>
}

class Window {
public:
    Window(const unsigned int size_w, const unsigned int size_h);
private:
    SDL_Window* window_;
};

#endif