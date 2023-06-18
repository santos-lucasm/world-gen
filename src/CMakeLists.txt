include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(srclib tile.cpp world.cpp randomizer.cpp
            window.cpp game.cpp)