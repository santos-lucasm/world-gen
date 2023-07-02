#ifndef __TILE_H__
#define __TILE_H__

#include "scenes/main_scene/terrain_types.h"

class Tile
{
public:
    /// @brief Inits the tile to invalid and initial parameters
    /// Tile parameters will be set during world generation
    Tile();

    /// @brief Returns terrain_t for initialized terrains and NONE type
    /// for non initialized terrains
    terrain_t GetTerrain();

    /// @brief Set seed_ to true
    /// Used to inform that this is a start point in world generation
    void SetAsSeed();

    /// @brief Set init_ to true
    /// Called when this tile already have its terrain defined
    void Initialize();

    /// @brief Initializes tile terrain
    /// @param type terrain_t type to be assigned to terrain_
    /// valid values are positive and lesser than MAX_TERRAIN_TYPES value
    void SetTerrain(const unsigned int type);

    /// @brief Initializes tile terrain when using perlin noise function
    /// @param type value between 0 and 1 to be converted to a terrain
    void SetPerlinTerrain(double type);

    /// @brief Inform current tile seed status. Once tile is defined as a seed
    /// it'll always be a world seed
    /// @return TRUE if tile is a seed, false otherwise
    bool IsSeed();

    /// @brief Inform current tile initialization status. Once tile is
    /// initialized, it'll always be initialized
    /// @return TRUE if tile was already init, false otherwise
    bool IsInitialized();

private:
    /// @brief set to true if this tile is a seed tile
    bool seed_;

    /// @brief set to true when the tile is initialized
    bool init_;

    /// @brief terrain type associated with this tile
    terrain_t terrain_;
};

#endif