#include "windows/main_w/world.h"
#include "windows/main_w/randomizer.h"
#include <thread>
//-----------------------------------------------------------------------------
World::World(const unsigned int size_x, const unsigned int size_y)
    : size_x_(size_x), size_y_(size_y)
{
    if( !IsValidSize(size_x_) || !IsValidSize(size_y_) )
    {
        std::cout << "ERROR: Invalid world size" << std::endl;
        exit(1);
    }

    tiles_ = std::make_unique< std::unique_ptr<Tile[]> []>(size_y_);
    for(unsigned int i = 0; i < size_y_; ++i)
    {
        tiles_[i] = std::make_unique<Tile[]>(size_x_);
    }

    rand_ = std::make_unique<Randomizer>(MAX_TERRAIN_TYPES);
}
//-----------------------------------------------------------------------------
World::~World()
{

}
//-----------------------------------------------------------------------------
void World::ProceduralGeneration()
{
    SetWorldSeed(size_x_/2, size_y_/2);
    Generate(size_x_/2, size_y_/2);
}
//-----------------------------------------------------------------------------
void World::Draw()
{
    for(unsigned int i = 0; i < size_y_; ++i)
    {
        for(unsigned int j = 0; j < size_x_; ++j)
        {
            tiles_[i][j].Draw();
        }
        std::cout << std::endl;
    }
}
//-----------------------------------------------------------------------------
bool World::Generate(const unsigned int x, const unsigned int y)
{
    //TODO: Remove position, find all seeds and create a thread to each one
    if(x < 0 || x >= size_x_)
        return false;
    if(y < 0 || y >= size_y_)
        return false;
    if(tiles_[y][x].IsInitialized() )
        return false;

    // int n_mountains = 0, n_ground = 0, n_water = 0;

    tiles_[y][x].SetTerrain(rand_->Generate());
    tiles_[y][x].Initialize();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    Generate(x-1, y);
    Generate(x+1, y);
    Generate(x, y+1);
    Generate(x, y-1);
    return true;
}
//-----------------------------------------------------------------------------
bool World::IsValidSize(const unsigned int size)
{
    if(size < 1 || size > 1024)
    {
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------
void World::SetWorldSeed(const unsigned int x, const unsigned int y)
{
    tiles_[y][x].SetAsSeed();
}
//-----------------------------------------------------------------------------
