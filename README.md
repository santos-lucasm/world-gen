![cmake build status](https://github.com/santos-lucasm/world-gen/actions/workflows/cmake.yml/badge.svg?event=push)

## Ideas and objetives

- [ ] Use perlin noise to generate terrain types. (WIP)
- [ ] Navigate using mouse (zoom in, zoom out and drag). Enabling bigger world generation.
- [ ] Menu to set generation parameters (seed amount and location, terrain perlin noise threshold)
- [ ] Generate world using other distributions and use AI to approximate then to perlin noise pattern 

## Dependencies

Tested with WSL2 v5.10.16.3 using Linux Ubuntu 20.04 LTS

`libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev libsdl2-ttf-dev`


## Help cmake to find SDL libraries

Copy `sdl2_image-config.cmake` to `/usr/lib/x86_64-linux-gnu/cmake/sdl2_image/`

Copy `sdl2_ttf-config.cmake` to `/usr/lib/x86_64-linux-gnu/cmake/sdl2_ttf/`

## Special thanks

- [SonDanielson](https://sondanielson.itch.io/gameboy-simple-rpg-tileset) for the amazing tilesheet.

- [Abaddon](https://caffinate.itch.io/abaddon) for the amazing text fonts.

- [Reputeless](https://github.com/Reputeless/PerlinNoise/tree/master) for the perlin noise C++ library.
