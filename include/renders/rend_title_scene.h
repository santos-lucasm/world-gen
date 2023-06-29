#ifndef __REND_TITLE_SCENE_H__
#define __REND_TITLE_SCENE_H__

#include "renders/renderer.h"

/// @brief Responsible for rendering TitleScene
class RenderTitleScene : public IRenderer {
public:
    /// @brief Initializes rendering positions of objects
    /// @param size_w screen width
    /// @param size_h screen height
    RenderTitleScene(const unsigned int size_w, const unsigned int size_h);

    /// @brief Responsible for deallocating textures and sdl objects from heap
    ~RenderTitleScene();

    /// @brief Render scene objects every new frame
    void Render();
private:
    /// @brief Configure logo texture position and screen placement
    /// @param size_w screen width
    /// @param size_h screen height
    void SetLogo(const unsigned int size_w, const unsigned int size_h);

    /// @brief Configure caption font and screen placement
    /// @param size_w screen width
    /// @param size_h screen height
    void SetCaption(const unsigned int size_w, const unsigned int size_h);
private:
    /// @brief texture to render application logo
    SDL_Texture* logo_texture_ = {nullptr};

    /// @brief logo placement inside loaded texture tilesheet
    SDL_Rect logo_texture_position_ = {0};

    /// @brief logo screen placement
    SDL_Rect logo_screen_position_ = {0};

    /// @brief TTF font used to display title caption
    TTF_Font* caption_font_ = {nullptr};

    /// @brief texture to render caption title
    SDL_Texture* caption_texture_;

    /// @brief caption screen placement
    SDL_Rect caption_position_;
    
};

#endif