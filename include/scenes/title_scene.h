#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include <memory>
#include "scenes/scene.h"
#include "events/event_listener.h"

class RenderTitleScene;

/// @brief Scene responsible for starting app to user
class TitleScene : public IScene,
                  public EventListener {
public:
    /// @brief Init scene helpers
    /// @param size_w title scene width in pixels
    /// @param size_h title scene height in pixels
    TitleScene(const unsigned int size_w, const unsigned int size_h);

    /// @brief Default to call base destructor
    ~TitleScene();

    /// @brief Call scene render to draw internal objects
    void Draw() override;
private:
    /// @brief renderer used to render this scene
    std::unique_ptr<RenderTitleScene> title_scene_render_;
};
#endif