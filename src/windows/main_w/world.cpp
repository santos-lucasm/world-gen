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
void World::ProceduralGeneration(const unsigned int x, const unsigned int y)
{
    SetWorldSeed(x, y);
}
//-----------------------------------------------------------------------------
terrain_t World::GetTerrain(const unsigned int x, const unsigned int y)
{

    return tiles_[y][x].GetTerrain();
}
//------------- ----------------------------------------------------------------
std::tuple<const unsigned int, const unsigned int> World::GetWorldSize()
{
    return {size_x_, size_y_};
}
//------------- ----------------------------------------------------------------
bool World::Generate(const unsigned int x, const unsigned int y, int ref)
{
    if(x < 0 || x >= size_x_)
        return false;
    if(y < 0 || y >= size_y_)
        return false;
    if(tiles_[y][x].IsInitialized() )
        return false;

    int generated_terrain = 0;
    {
        std::scoped_lock lock(tiles_guard_);
        if(tiles_[y][x].IsSeed() && ref == 0)
        {
            generated_terrain = rand_->Generate();
        }
        else
        {
            generated_terrain = rand_->Generate(ref);
        }
        tiles_[y][x].SetTerrain(generated_terrain);
        tiles_[y][x].Initialize();
    }
#ifdef DEBUG
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
#endif

    if(tiles_[y][x].IsSeed())
    {
        Generate(x-1, y, generated_terrain);
        Generate(x+1, y, generated_terrain);
        Generate(x, y+1, generated_terrain);
        Generate(x, y-1, generated_terrain);
    }
    else
    {
        Generate(x-1, y, ref);
        Generate(x+1, y, ref);
        Generate(x, y+1, ref);
        Generate(x, y-1, ref);
    }
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
    {
        std::scoped_lock lock(tiles_guard_);
        tiles_[y][x].SetAsSeed();
    }
    Generate(x, y, 0);
}
//-----------------------------------------------------------------------------
