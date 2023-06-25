#ifndef __REND_MAIN_SCENE_H__
#define __REND_MAIN_SCENE_H__

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

#include <map>

class RenderMainScene {
public:
    /// @brief 
    /// @param size_w 
    /// @param size_h 
    RenderMainScene(const unsigned int size_w, const unsigned int size_h);

    /// @brief Destroy renderer and window references
    ~RenderMainScene();

    /// @brief Render world tiles using rectangles in grey scale
    /// @param world World being procedural generated
    void Render(std::shared_ptr<World> world);
private:
    /// @brief Clears whole scene setting it to black color
    void ClearWindow();
private:
    /// @brief Maps terrain types to RGB colors
    static std::map<terrain_t, std::tuple<uint8_t, uint8_t, uint8_t>> color_map_;

    /// @brief SDL window reference where objects will be rendered
    SDL_Window* window_;

    /// @brief not used for now
    SDL_Texture* texture_;

    /// @brief SDL renderer reference used to render objects
    SDL_Renderer* sdl_renderer_;
};

#endif