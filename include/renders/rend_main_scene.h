#ifndef __REND_MAIN_SCENE_H__
#define __REND_MAIN_SCENE_H__

#include <map>
#include "renders/renderer.h"

/// @brief Responsible for rendering main scene objects
class RenderMainScene : public IRenderer {
public:
    /// @brief Just calls base class constructor
    /// @param size_w window width
    /// @param size_h window height
    RenderMainScene(const unsigned int size_w, const unsigned int size_h);

    /// @brief Render world tiles using rectangles in grey scale
    /// @param world World being procedural generated
    void Render(std::shared_ptr<World> world);
private:
    /// @brief Maps terrain types to RGB colors
    static std::map<terrain_t, std::tuple<uint8_t, uint8_t, uint8_t>> color_map_;
};

#endif