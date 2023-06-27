#ifndef __REND_TITLE_SCENE_H__
#define __REND_TITLE_SCENE_H__

#include "renders/renderer.h"

class RenderTitleScene : public IRenderer {
public:
    /// @brief 
    /// @param size_w 
    /// @param size_h 
    RenderTitleScene(const unsigned int size_w, const unsigned int size_h);

    /// @brief Render app title background
    void Render();
private:
    /// @brief Clears whole scene setting it to black color
    void ClearWindow();

    /// @brief rectangle that covers texture inside the tilesheet
    SDL_Rect texture_position_;

    /// @brief rectangle that positions texture relative to screen
    SDL_Rect title_position_;
    TTF_Font* text_font_;
    SDL_Surface* text_surface_;
    SDL_Texture* text_texture_;
    SDL_Rect text_position_;
    
};

#endif