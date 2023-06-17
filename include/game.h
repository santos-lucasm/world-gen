#ifndef __GAME_H__
#define __GAME_H__

#include <memory>
#include "window.h"
#include "world.h"

class Game {
public:
    Game();

    void Run();
private:
    std::unique_ptr<Window> window_;
    std::unique_ptr<World> world_;
};

#endif