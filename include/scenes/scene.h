#ifndef __SCENE_H__
#define __SCENE_H__

/// @brief Scenes interface
class IScene {
public:
    IScene() {};

    ~IScene() = default;

    /// @brief Used to render the scene
    virtual void Draw() = 0;
};

#endif