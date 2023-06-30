include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(main_scene)

add_library(libscenes main_scene.cpp title_scene.cpp)