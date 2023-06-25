#ifndef __REND_TITLE_SCENE_H__
#define __REND_TITLE_SCENE_H__

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

class RenderTitleScene {
public:
    /// @brief 
    /// @param size_w 
    /// @param size_h 
    RenderTitleScene(const unsigned int size_w, const unsigned int size_h);

    /// @brief Destroy renderer and window references
    ~RenderTitleScene();

    void Render();
private:
    /// @brief Clears whole scene setting it to black color
    void ClearWindow();
private:
    /// @brief SDL window reference where objects will be rendered
    SDL_Window* window_;

    /// @brief not used for now
    SDL_Texture* texture_;

    /// @brief SDL renderer reference used to render objects
    SDL_Renderer* sdl_renderer_;
};

#endif