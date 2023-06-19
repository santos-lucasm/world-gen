#ifndef __RANDOMIZER_H__
#define __RANDOMIZER_H__

#include <random>
#include "windows/main_w/tile.h"

// std::mt19937 rng_;

class Randomizer {
public:

    Randomizer(const unsigned int max_value);

    /// @brief 0.1 per adjacent tile of a type
    /// if its a seed, than choose random without additional chances
    int Generate();
private:
    std::normal_distribution<float> normal_dist_;
    std::uniform_int_distribution<std::mt19937::result_type> uniform_dist_;
    std::mt19937 rng_;
};



#endif