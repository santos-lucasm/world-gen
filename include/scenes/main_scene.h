#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include <memory>
#include "scenes/scene.h"
#include "events/event_listener.h"

class World;
class RenderMainScene;

/// @brief Scene responsible for running the procedural generation
class MainScene : public IScene,
                  public EventListener {
public:
    /// @brief Create window, init scene helpers and start procedural
    /// generation threads
    /// @param size_w main scene width in pixels
    /// @param size_h main scene height in pixels
    MainScene(const unsigned int size_w, const unsigned int size_h);

    /// @brief Default to call base destructor
    ~MainScene();

    /// @brief Call scene render to draw internal objects
    void Draw() override;

    /// @brief called in PAUSE_TRIGGERED event
    /// @param entered_pause_mode true if entering pause, false otherwise
    void OnPause(bool entered_pause_mode) override;
private:
    /// @brief procedural generated world object of this scene
    std::shared_ptr<World> world_;

    /// @brief renderer used to render this scene
    std::unique_ptr<RenderMainScene> main_scene_render_;
};
#endif