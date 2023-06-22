#ifndef __MAIN_W_H__
#define __MAIN_W_H__

#include <memory>
#include <thread>
#include "windows/window.h"

class World;
class RenderMainWindow;
class FsmMainScene;
enum class Event;

class MainScene : public Window {
public:
    /// @brief Create window, init scene helpers and start procedural
    /// generation threads
    /// @param size_w main scene width in pixels
    /// @param size_h main scene height in pixels
    MainScene(const unsigned int size_w, const unsigned int size_h);

    /// @brief Default to call base destructor
    ~MainScene();

    /// @brief Update scene state according to received event
    /// @param e Received event
    void Update(Event e) override;

    /// @brief Call scene render to draw internal objects
    void Draw() override;
private:
    std::shared_ptr<World> world_;
    std::unique_ptr<RenderMainWindow> w_render_;
    std::unique_ptr<FsmMainScene> fsm_;
    const unsigned int x_blocks_;
    const unsigned int y_blocks_;
};
#endif