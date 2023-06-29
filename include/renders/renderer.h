#ifndef __RENDERER_H__
#define __RENDERER_H__

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
}

/// @brief Renderers interface that stores references to SDL_Window and renders
class IRenderer {
public:
    /// @brief Default constructor that init window and renderer the first time
    /// it's called. Other renderers that init from this will not create a new
    /// window and renderer instance for now.
    /// @param size_w window width size 
    /// @param size_h window height size
    IRenderer(const unsigned int size_w, const unsigned int size_h);

    /// @brief Destroy renderer and window references
    ~IRenderer();
protected:
    // FIXME: Force derivate classes to implement Render, but each class
    // may need its own parameters to be rendered...
    // void Render() = 0;

    /// @brief Clears whole scene with the current draw color
    void ClearWindow();
private:
    /// @brief Initializes window instance
    void InitWindow(const unsigned int size_w, const unsigned int size_h);

    /// @brief Initializes renderer instance
    void InitRenderer();
protected:
    /// @brief SDL window reference where objects will be rendered
    static SDL_Window* window_;

    /// @brief SDL renderer reference used to render objects
    static SDL_Renderer* renderer_;
};


#endif