#ifndef __RANDOMIZER_H__
#define __RANDOMIZER_H__

#include <random>
#include "utils/perlin_noise.h"

class Randomizer {
public:

    Randomizer(const unsigned int max_value);

    int Generate();

    int Generate(int ref);

    double PerlinNoise(int x, int y);
private:
    /// @brief Used to generate random values around a reference
    std::normal_distribution<float> normal_dist_;

    /// @brief Used to generate values randomly uniform in an interval 
    std::uniform_int_distribution<std::mt19937::result_type> uniform_dist_;

    /// @brief Used to generate natural random values from [0, 1]
    static siv::PerlinNoise perlin_dist_;

    /// @brief seed
    std::mt19937 rng_;
};



#endif