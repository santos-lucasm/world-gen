include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(application)
add_subdirectory(scenes)
add_subdirectory(renders)
add_subdirectory(utils)
add_subdirectory(events)
# add_library(libsrc game.cpp)