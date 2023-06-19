include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(windows)

add_library(srclib tile.cpp world.cpp randomizer.cpp
game.cpp renderer.cpp windows/window.cpp)