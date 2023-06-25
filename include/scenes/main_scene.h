#ifndef __MAIN_W_H__
#define __MAIN_W_H__

#include <memory>
#include "scenes/scene.h"
#include "events/event_listener.h"

class World;
class RenderMainScene;
enum class Event;

class MainScene : public Scene,
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

    void OnPause(bool entered_pause_mode) override;
private:
    std::shared_ptr<World> world_;
    std::unique_ptr<RenderMainScene> w_render_;
    const unsigned int x_blocks_;
    const unsigned int y_blocks_;
};
#endif