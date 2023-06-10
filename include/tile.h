#ifndef __TILE_H__
#define __TILE_H__

#define MAX_TERRAIN_TYPES 4

/// @brief Current terrain types supported in world generation
enum
{
    NONE,
    WATER,
    GROUND,
    MOUNTAIN
} typedef terrain_t;

class Tile
{
public:
    /// @brief Inits the tile to invalid and initial parameters
    /// Tile parameters will be set during world generation
    Tile();

    /// @brief Just print the terrain type in integer format to the std output
    /// Output format is "(int)<terrain_t> "
    void Draw();

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