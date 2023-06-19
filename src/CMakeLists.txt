include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(windows)
add_subdirectory(renders)

add_library(libsrc game.cpp)