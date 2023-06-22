include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(main_w)

add_library(libwindows window.cpp main_scene.cpp)