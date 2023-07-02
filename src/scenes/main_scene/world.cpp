#include <thread>
#include <cassert>
#include "scenes/main_scene/world.h"
#include "utils/randomizer.h"
#include "scenes/main_scene/tile.h"

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
World::World(const unsigned int size_x, const unsigned int size_y)
    : size_x_(size_x), size_y_(size_y)
{
    assert(IsValidSize(size_x_) && IsValidSize(size_y_));

    tiles_ = std::make_unique< std::unique_ptr<Tile[]> []>(size_y_);
    for(unsigned int i = 0; i < size_y_; ++i)
    {
        tiles_[i] = std::make_unique<Tile[]>(size_x_);
    }

    rand_ = std::make_unique<Randomizer>(MAX_TERRAIN_TYPES);
    std::atomic_exchange(&is_running_, false);
}
//-----------------------------------------------------------------------------
World::~World() = default;
//-----------------------------------------------------------------------------
void World::ProceduralGeneration(const unsigned int x, const unsigned int y)
{
    static int n_threads_running = 0;
    n_threads_running++;
    //FIXME: identify if paused state to not auto start (maybe?)
    std::atomic_exchange(&is_running_, true);

    SetWorldSeed(x, y);

    n_threads_running--;
    if(n_threads_running == 0)
    {
        std::atomic_exchange(&is_running_, false);
    }
}
//-----------------------------------------------------------------------------
terrain_t World::GetTerrain(const unsigned int x, const unsigned int y)
{
    assert(size_x_ > x && size_y_ > y);
    return tiles_[y][x].GetTerrain();
}
//------------------------------------------------------------------------------
std::tuple<const unsigned int, const unsigned int> World::GetWorldSize()
{
    return {size_x_, size_y_};
}
//------------------------------------------------------------------------------
void World::Pause()
{
    if(std::atomic_load(&is_running_))
    {
        std::atomic_exchange(&is_running_, false);
    }
}
//------------------------------------------------------------------------------
void World::Play()
{
    if(false == std::atomic_load(&is_running_))
    {
        std::atomic_exchange(&is_running_, true);
    }
}
//------------------------------------------------------------------------------
bool World::Generate(const unsigned int x, const unsigned int y, int ref)
{
    if(x < 0 || x >= size_x_)
        return false;
    if(y < 0 || y >= size_y_)
        return false;
    if(tiles_[y][x].IsInitialized() )
        return false;

#ifdef DEBUG
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
#endif
    // spin lock if generation is not running anymore (user pause)
    while(false == std::atomic_load(&is_running_));

    int generated_terrain = 0;
    {
        std::scoped_lock lock(tiles_guard_);
        if(tiles_[y][x].IsSeed() && ref == 0)
        {
            generated_terrain = rand_->GenerateWithUniformDist();
        }
        else
        {
            generated_terrain = rand_->GenerateWithNormalDist(ref);
        }
        tiles_[y][x].SetTerrain(generated_terrain);
        tiles_[y][x].Initialize();
    }

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
bool World::Generate(const unsigned int x, const unsigned int y)
{
    if(x < 0 || x >= size_x_)
        return false;
    if(y < 0 || y >= size_y_)
        return false;
    if(tiles_[y][x].IsInitialized() )
        return false;

#ifdef DEBUG
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
#endif
    // spin lock if generation is not running anymore (user pause)
    while(false == std::atomic_load(&is_running_));

    double generated_terrain = 0;
    {
        std::scoped_lock lock(tiles_guard_);
        generated_terrain = rand_->PerlinNoise(x, y);
        tiles_[y][x].SetPerlinTerrain(generated_terrain);
        tiles_[y][x].Initialize();
    }

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
    {
        std::scoped_lock lock(tiles_guard_);
        tiles_[y][x].SetAsSeed();
    }
    Generate(x, y);
}
//-----------------------------------------------------------------------------
