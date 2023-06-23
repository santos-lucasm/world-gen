#ifndef __REND_MAIN_W_H__
#define __REND_MAIN_W_H__

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

#include <map>

class RenderMainScene {
public:
    RenderMainScene(const unsigned int size_w, const unsigned int size_h);

    ~RenderMainScene();

    void Render(std::shared_ptr<World> world);
private:
    // maps terrain to a color
    std::map<terrain_t, std::tuple<uint8_t, uint8_t, uint8_t>> color_map_;
private:
    SDL_Window* window_;
    SDL_Texture* texture_;
    SDL_Renderer* sdl_renderer_;
};

#endif