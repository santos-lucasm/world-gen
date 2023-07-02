#ifndef __WORLD_H__
#define __WORLD_H__

#include <memory>
#include <mutex>
#include <atomic>
#include "scenes/main_scene/terrain_types.h"

class Randomizer;
class Tile;

class World
{
public:
    /// @brief Responsible for validating user entered size.
    /// X and Y sizes need to be in [1, 1024] interval, otherwise an error
    /// is raised indicating invalid world size.
    /// @param size_x Horizontal total size of the generated world
    /// @param size_y Vertical total size of the generated world
    World(const unsigned int size_x, const unsigned int size_y);

    /// @brief Default destructor
    ~World();

    /// @brief Start procedural generation by seting world seed and
    /// calling Generate function
    /// @param x seed x position in tile matrix
    /// @param y seed y position in tile matrix
    void ProceduralGeneration(const unsigned int x, const unsigned int y);

    /// @brief Retrive terrain of the tile according to its matrix position
    /// @param x tile x position in tile matrix
    /// @param y tile y position in tile matrix
    /// @return terrain type of the corresponding tile
    terrain_t GetTerrain(const unsigned int x, const unsigned int y);

    /// @brief returns world size in tiles
    /// @return returns x and y tuple of the world tiles
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

    /// @brief Initialize all tiles using randomizer normal and uniform dist
    /// @param x onedimensional position in matrix tile 
    /// @param y onedimensional position in matrix tile
    /// @param ref generated terrain value for the seed
    /// @return true when all tiles are generated, false for tiles out of
    /// matrix bound and already initialized tiles
    bool Generate(const unsigned int x, const unsigned int y, int ref);

    /// @brief Initialize all tiles using PerlinNoise function
    /// @param x onedimensional position in matrix tile 
    /// @param y onedimensional position in matrix tile
    /// @return true when all tiles are generated, false for tiles out of
    /// matrix bound and already initialized tiles
    bool Generate(const unsigned int x, const unsigned int y);

    /// @brief Chooose the matrix position to be associated with a seed
    /// @param x x matrix coordinate
    /// @param y y matrix coordinate
    void SetWorldSeed(const unsigned int x, const unsigned int y);

private:
    /// @brief world tile width size
    const unsigned int size_x_;

    /// @brief world tile height size
    const unsigned int size_y_;

    /// @brief world matrix of tiles
    std::unique_ptr<std::unique_ptr<Tile[]>[]> tiles_;

    /// @brief randomizer used to generate terrain for the tiles
    std::unique_ptr<Randomizer> rand_;

    /// @brief used for mutual exclusion in tile terrain generation
    std::mutex tiles_guard_;

    /// @brief determines if procedural generation is running or not
    std::atomic<bool> is_running_;
};

#endif