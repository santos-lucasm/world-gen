#ifndef __MAIN_W_H__
#define __MAIN_W_H__

#include "windows/window.h"
#include <memory>

class World;

class MainWindow : public Window {
public:
    MainWindow(const unsigned int size_w, const unsigned int size_h);

    ~MainWindow();

    void Update() override;
private:
    std::unique_ptr<World> world_;
};
#endif