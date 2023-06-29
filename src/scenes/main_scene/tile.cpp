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
    terrain_ = static_cast<terrain_t>(type);
}
//-----------------------------------------------------------------------------
void Tile::SetPerlinTerrain(double type)
{
    if(type <= 0.25)
    {
        terrain_ = terrain_t::WATER;
    }
    else if(type <= 0.50)
    {
        terrain_ = terrain_t::GROUND;
    }
    else if(type <= 0.75)
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
