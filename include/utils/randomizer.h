#ifndef __RANDOMIZER_H__
#define __RANDOMIZER_H__

#include <random>
#include "utils/perlin_noise.h"

/// @brief Generate random values using distributions
class Randomizer {
public:
    /// @brief set random seed and init some distributions
    /// @param max_value higher value that can be generated
    /// using any of the distributions of this class
    Randomizer(const unsigned int max_value);

    /// @brief Generate an integer using uniform distribution
    /// @return an integer in [1, max_value] interval
    int GenerateWithUniformDist();

    /// @brief Generate an integer using normal distribution
    /// If the generated integer is above maximum valid value
    /// or equal to zero, the integer is generated again using
    /// uniform distribution
    /// @param ref median value (the value with most chances)
    /// @return an integer in [1, max_value] interval
    int GenerateWithNormalDist(int ref);

    /// @brief Generate an floating point value using perlin noise
    /// @param x noise position in x axis
    /// @param y noise position in y axis
    /// @return floating point between 0 and 1
    double PerlinNoise(int x, int y);
private:
    /// @brief Used to generate random values around a reference
    std::normal_distribution<float> normal_dist_;

    /// @brief Used to generate values randomly uniform in an interval 
    std::uniform_int_distribution<std::mt19937::result_type> uniform_dist_;

    /// @brief Used to generate natural random values in [0, 1] interval
    static siv::PerlinNoise perlin_dist_;

    /// @brief seed
    std::mt19937 rng_;

    /// @brief higher value that can be generated using any of the functions
    const unsigned int max_generated_value_;
};



#endif