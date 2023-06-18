#ifndef __WINDOW_H__
#define __WINDOW_H__

extern "C" {
    #include <SDL2/SDL.h>
}

#include <string>

class Window {
public:
    Window(const unsigned int size_w, const unsigned int size_h);

    ~Window();

    const std::string GetTitle();
private:
    SDL_Window* window_;
};

#endif