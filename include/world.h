#ifndef __WORLD_H__
#define __WORLD_H__

#include <iostream>
#include "tile.h"
#include "randomizer.h"
//TODO: finish documentation

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


    void ProceduralGeneration();

    /// @brief Draw all the world tiles in the correct order
    void Draw();


private:

    /// @brief Verifies if size is in [1, 1024]
    /// @param size X or Y size of world to be generated
    /// @return TRUE if size is in the interval, false otherwise
    bool IsValidSize(const unsigned int size);

    /// @brief 
    /// @param x onedimensional position in matrix tile 
    /// @param y onedimensional position in matrix tile
    /// @return 
    bool Generate(int x, int y);

    void SetWorldSeed(const unsigned int x, const unsigned int y);

private:
    const unsigned int size_x_;
    const unsigned int size_y_;
    //TODO: Use smart pointer
    Tile ** tiles_;
    Randomizer * rand_;
};

#endif