#include <cassert>
#include "scenes/main_scene/tile.h"
//-----------------------------------------------------------------------------
Tile::Tile() : seed_(false), init_(false), terrain_(terrain_t::NONE)
{

}
//-----------------------------------------------------------------------------
terrain_t Tile::GetTerrain()
{
    return terrain_;
}
//-----------------------------------------------------------------------------
void Tile::SetAsSeed()
{
    seed_ = true;
}
//-----------------------------------------------------------------------------
void Tile::SetTerrain(const unsigned int type)
{
    assert((0 <= type) && (MAX_TERRAIN_TYPES > type));

    terrain_ = static_cast<terrain_t>(type);
}
//-----------------------------------------------------------------------------
void Tile::SetPerlinTerrain(double type)
{
    assert((0 <= type) && (1 >= type));
    if(0.25 >= type)
    {
        terrain_ = terrain_t::WATER;
    }
    else if(0.50 >= type)
    {
        terrain_ = terrain_t::GROUND;
    }
    else if(0.75 >= type)
    {
        terrain_ = terrain_t::HILL;
    }
    else
    {
        terrain_ = terrain_t::MOUNTAIN;
    }
}
//-----------------------------------------------------------------------------
void Tile::Initialize()
{
    init_ = true;
}
//-----------------------------------------------------------------------------
bool Tile::IsSeed()
{
    return seed_;
}
//-----------------------------------------------------------------------------
bool Tile::IsInitialized()
{
    return init_;
}
//-----------------------------------------------------------------------------
