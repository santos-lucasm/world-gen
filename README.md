![cmake build status](https://github.com/santos-lucasm/world-gen/actions/workflows/cmake.yml/badge.svg?event=push)

## CODE PATTERNS

* Event driven
Game class keeps the main loop, polling and handling events, updating and rendering scenes. 

* Observer pattern
EventManager acts like the notifier. Classes that inherit from EventListener can subscribe to specific events.

* Singleton pattern
EventManager is also a singleton, so different code sections can easily subscribe as event listeners.

## Dependencies

Tested with WSL2 v5.10.16.3 using Linux Ubuntu 20.04 LTS

`libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev libsdl2-ttf-dev`


## Help cmake to find SDL Image library

Copy `sdl2_image-config.cmake` to `/usr/lib/x86_64-linux-gnu/cmake/sdl2_image/`
Copy `sdl2_ttf-config.cmake` to `/usr/lib/x86_64-linux-gnu/cmake/sdl2_ttf/`

## Special thanks

- [SonDanielson](https://sondanielson.itch.io/gameboy-simple-rpg-tileset) for the amazing tilesheet.

- [Abaddon](https://caffinate.itch.io/abaddon) for the amazing text fonts.

- [Reputeless](https://github.com/Reputeless/PerlinNoise/tree/master) for the perlin noise C++ library.