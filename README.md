![cmake build status](https://github.com/santos-lucasm/world-gen/actions/workflows/cmake.yml/badge.svg?event=push)
![codeql build status](https://github.com/santos-lucasm/world-gen/actions/workflows/codeql.yml/badge.svg?event=push)

## Ideas and objetives

- [ ] Use perlin noise to generate terrain types. (WIP)
- [ ] Navigate using mouse (zoom in, zoom out and drag). Enabling bigger world generation.
- [ ] Menu to set generation parameters (seed amount and location, terrain perlin noise threshold)
- [ ] Generate world using other distributions and use AI to approximate then to perlin noise pattern 

## Requirements

- REQ01: Application should start at TitleScene
- REQ02: TitleScene shall display "Procedural generation" and some procedural animated tiles generated with it
- REQ03: TitleScene shall display "PRESS SPACEBAR TO CONTINUE..." below the generated tiles
- REQ04: At TitleScene, by pressing <SPACEBAR> application shall open a white background (MainScene at paused state) and a moving black window (SetupScene) shall appear from the left border of the screen stopping after occupying 40% of window width.
- REQ05: SetupScene shall hide moving towards left border or appear from left border every time user press <TAB>
- REQ06: User may click anywhere on the white background to select that tile and make it a procedural seed. User may choose more than one seed. User may choose seeds with SetupScene opened, but only at white background.
- REQ07: Press Start button in SetupScene to start generating tiles from the choosen seeds (all the same time)

## Build

Help cmake to find the SDL2 libraries

```
sudo mkdir /usr/lib/x86_64-linux-gnu/cmake/sdl2_image
sudo mkdir /usr/lib/x86_64-linux-gnu/cmake/sdl2_ttf
sudo cp cmake/sdl2_image-config.cmake /usr/lib/x86_64-linux-gnu/cmake/sdl2_image/sdl2_image-config.cmake
sudo cp cmake/sdl2_ttf-config.cmake /usr/lib/x86_64-linux-gnu/cmake/sdl2_ttf/sdl2_ttf-config.cmake
```

```
mkdir build && cd build
cmake ..
make

ln -s compile_commands.json ../
```

Tested with:
- WSL2 v5.10.16.3 using Linux Ubuntu 20.04 LTS
- Zorin OS 17.2 x86_64

`sudo apt install libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev libsdl2-ttf-dev`

## Special thanks

- [SonDanielson](https://sondanielson.itch.io/gameboy-simple-rpg-tileset) for the amazing tilesheet.

- [Abaddon](https://caffinate.itch.io/abaddon) for the amazing text fonts.

- [Reputeless](https://github.com/Reputeless/PerlinNoise/tree/master) for the perlin noise C++ library.
