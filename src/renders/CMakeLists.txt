include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(librenders
    renderer.cpp
    rend_main_scene.cpp
    rend_title_scene.cpp
)