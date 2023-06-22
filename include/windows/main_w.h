#ifndef __MAIN_W_H__
#define __MAIN_W_H__

#include <memory>
#include <vector>
#include <thread>
#include "windows/window.h"

class World;
class RenderMainWindow;
class FsmMainScene;
enum class Event;

class MainWindow : public Window {
public:
    MainWindow(const unsigned int size_w, const unsigned int size_h);

    ~MainWindow();

    void Update(Event e) override;

    void Draw() override;
private:
    std::shared_ptr<World> world_;
    std::unique_ptr<RenderMainWindow> w_render_;
    std::unique_ptr<FsmMainScene> fsm_;
    const unsigned int x_blocks_;
    const unsigned int y_blocks_;
};
#endif