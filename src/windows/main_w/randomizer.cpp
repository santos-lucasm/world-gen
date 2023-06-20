#include "windows/main_w/randomizer.h"
#include <iostream>
#include <cmath>
//-----------------------------------------------------------------------------
Randomizer::Randomizer(const unsigned int max_value)
{
    std::random_device dev;
    rng_ = std::mt19937( dev() );
    
    uniform_dist_ = std::uniform_int_distribution<std::mt19937::result_type>
        (1, max_value);
}
//-----------------------------------------------------------------------------
int Randomizer::Generate()
{
    // receive 3 weights: 0.25 per adjacent tile of a specific terrain
    // Ex: If 3 mountains are around this tile, roll the normal distribution
    // around 1 with 0.2 of std deviation. If the number is around up to 0.75
    // from 1 satifies this equation: |x - 1| < 0.75, the same terrain is used
    // auto gen = std::abs(static_cast<float>(normal_dist_(rng_) - 1));

    return uniform_dist_(rng_);
}
//-----------------------------------------------------------------------------
int Randomizer::Generate(int ref)
{
    normal_dist_ = std::normal_distribution<float>(ref, 0.5);
    int gen = std::abs(normal_dist_(rng_));
    return (gen == 0 || gen > 3) ? 1 : gen;
}
//-----------------------------------------------------------------------------
