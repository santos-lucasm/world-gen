#ifndef __TERRAIN_TYPES_H__
#define __TERRAIN_TYPES_H__

#define MAX_TERRAIN_TYPES 3

/// @brief Current terrain types supported in world generation
enum
{
    NONE,
    WATER,
    GROUND,
    MOUNTAIN
} typedef terrain_t;

#endif