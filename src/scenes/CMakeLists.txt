include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(main_w)

add_library(libwindows scene.cpp main_scene.cpp)