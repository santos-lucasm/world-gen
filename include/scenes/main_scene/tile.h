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

    void SetTerrain(const unsigned int type);

    /// @brief Inform current tile seed status. Once tile is defined as a seed
    /// it'll always be a world seed
    /// @return TRUE if tile is a seed, false otherwise
    bool IsSeed();

    /// @brief Inform current tile initialization status. Once tile is
    /// initialized, it'll always be initialized
    /// @return TRUE if tile was already init, false otherwise
    bool IsInitialized();

private:
    bool seed_;
    bool init_;
    terrain_t terrain_;
};

#endif