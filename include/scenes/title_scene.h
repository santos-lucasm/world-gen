#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include <memory>
#include "scenes/scene.h"
#include "events/event_listener.h"

class RenderTitleScene;

class TitleScene : public Scene,
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

    // void OnPause(bool entered_pause_mode) override;
private:
    std::unique_ptr<RenderTitleScene> render_;
};
#endif