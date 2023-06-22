include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(main_scene)

add_library(libscenes scene.cpp main_scene.cpp)