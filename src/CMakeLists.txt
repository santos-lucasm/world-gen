include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(scenes)
add_subdirectory(renders)
add_subdirectory(fsm)

add_library(libsrc game.cpp)