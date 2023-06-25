#ifndef __WORLD_H__
#define __WORLD_H__

#include <memory>
#include <tuple>
#include <mutex>
#include <atomic>
#include "scenes/main_scene/tile.h"

class Randomizer;

class World
{
public:
    /// @brief Responsible for validating user entered size.
    /// X and Y sizes need to be in [1, 1024] interval, otherwise an error
    /// is raised indicating invalid world size.
    /// @param size_x Horizontal total size of the generated world
    /// @param size_y Vertical total size of the generated world
    World(const unsigned int size_x, const unsigned int size_y);

    /// @brief Deallocates all memmory from heap
    ~World();

    void ProceduralGeneration(const unsigned int x, const unsigned int y);

    /// @brief Retrieve terrain type of a specific Tile
    terrain_t GetTerrain(const unsigned int x, const unsigned int y);

    std::tuple<const unsigned int, const unsigned int> GetWorldSize();

    /// @brief Pause ProceduralGeneration if it's running
    void Pause();

    /// @brief Play ProceduralGeneration again if it's paused
    void Play();

private:

    /// @brief Verifies if size is in [1, 1024]
    /// @param size X or Y size of world to be generated
    /// @return TRUE if size is in the interval, false otherwise
    bool IsValidSize(const unsigned int size);

    /// @brief 
    /// @param x onedimensional position in matrix tile 
    /// @param y onedimensional position in matrix tile
    /// @return 
    bool Generate(const unsigned int x, const unsigned int y, int ref);
    bool Generate(const unsigned int x, const unsigned int y);

    void SetWorldSeed(const unsigned int x, const unsigned int y);

private:
    const unsigned int size_x_;
    const unsigned int size_y_;

    std::unique_ptr<std::unique_ptr<Tile[]>[]> tiles_;
    std::unique_ptr<Randomizer> rand_;
    std::mutex tiles_guard_;
    std::atomic<bool> is_running_;
};

#endif