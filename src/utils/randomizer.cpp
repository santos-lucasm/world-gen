#include "utils/randomizer.h"
#include <cmath>
//-----------------------------------------------------------------------------
siv::PerlinNoise Randomizer::perlin_dist_ = siv::PerlinNoise(
    std::random_device{});
//-----------------------------------------------------------------------------
Randomizer::Randomizer(const unsigned int max_value)
    : max_generated_value_(max_value)
{
    // configure seed
    std::random_device dev;
    rng_ = std::mt19937( dev() );

    // configure distributions
    uniform_dist_ = std::uniform_int_distribution<std::mt19937::result_type>
        (1, max_generated_value_);

    perlin_dist_.reseed(rng_);
}
//-----------------------------------------------------------------------------
int Randomizer::GenerateWithUniformDist()
{
    return uniform_dist_(rng_);
}
//-----------------------------------------------------------------------------
int Randomizer::GenerateWithNormalDist(int ref)
{
    normal_dist_ = std::normal_distribution<float>(ref, 0.5);
    unsigned int gen = std::abs(normal_dist_(rng_));
    
    // Normal distribution returned a value out of bounds, randomize again using
    // uniform distribution
    return (gen == 0 || gen > max_generated_value_) ? uniform_dist_(rng_) : gen;
}
//-----------------------------------------------------------------------------
double Randomizer::PerlinNoise(int x, int y)
{
    return perlin_dist_.octave2D_01(x * 0.1, y * 0.1, 4);
}
//-----------------------------------------------------------------------------
