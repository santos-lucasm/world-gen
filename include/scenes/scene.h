#ifndef __SCENE_H__
#define __SCENE_H__

/// @brief Base abstract class for Scenes
/// Will be used in storage with polymorphism
class Scene {
public:
    Scene();

    ~Scene();

    /// @brief Used to render the scene
    virtual void Draw() = 0;
};

#endif