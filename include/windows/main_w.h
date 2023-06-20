#ifndef __MAIN_W_H__
#define __MAIN_W_H__

#include <memory>
#include <vector>
#include <thread>
#include "windows/window.h"

class World;
class RenderMainWindow;
//TODO: docs
class MainWindow : public Window {
public:
    MainWindow(const unsigned int size_w, const unsigned int size_h);

    ~MainWindow();

    void Update() override;

    void Draw() override;
private:
    std::shared_ptr<World> world_;
    std::unique_ptr<RenderMainWindow> w_render_;
    std::vector<std::thread> world_seeds_;

    const unsigned int x_blocks_;
    const unsigned int y_blocks_;
};
#endif