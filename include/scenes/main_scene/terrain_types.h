#ifndef __TERRAIN_TYPES_H__
#define __TERRAIN_TYPES_H__

#define MAX_TERRAIN_TYPES 4

/// @brief Current terrain types supported in world generation
enum
{
    NONE,
    WATER,
    GROUND,
    HILL,
    MOUNTAIN
} typedef terrain_t;

#endif