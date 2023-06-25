![cmake build status](https://github.com/santos-lucasm/world-gen/actions/workflows/cmake.yml/badge.svg?event=push)
![codeql build status](https://github.com/santos-lucasm/world-gen/actions/workflows/codeql.yml/badge.svg?event=push)

## CODE PATTERNS

* Event driven
Game class keeps the main loop, polling and handling events, updating and rendering scenes. 

* Observer pattern
EventManager acts like the notifier. Classes that inherit from EventListener can subscribe to specific events.

* Singleton pattern
EventManager is also a singleton, so different code sections can easily subscribe as event listeners.

## Dependencies

Tested with WSL2 v5.10.16.3 using Linux Ubuntu 20.04 LTS

`libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev`


## Help cmake to find SDL Image library

Create file `/usr/lib/x86_64-linux-gnu/cmake/sdl2_image/sdl2_image-config.cmake`

Add the following content:

```
set(prefix "/usr") 
set(exec_prefix "${prefix}")
set(libdir "${prefix}/lib/x86_64-linux-gnu")
set(SDL2_IMAGE_PREFIX "/usr")
set(SDL2_IMAGE_EXEC_PREFIX "/usr")
set(SDL2_IMAGE_INCLUDE_DIRS "${prefix}/include/SDL2_image")
set(SDL2_IMAGE_LIBRARIES "-lSDL2_image")
```
