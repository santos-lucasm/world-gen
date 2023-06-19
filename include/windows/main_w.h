#ifndef __MAIN_W_H__
#define __MAIN_W_H__

#include "windows/window.h"

class MainWindow : public Window {
public:
    MainWindow(const unsigned int size_w, const unsigned int size_h);

    ~MainWindow();

    void Update() override;
};
#endif