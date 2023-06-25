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
};

#endif