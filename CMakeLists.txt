project(world-gen)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -pthread -lm")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -pthread -lm")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

find_package(SDL2 REQUIRED sdl2)
find_package(SDL2_image REQUIRED)
add_executable(${PROJECT_NAME} app.cpp)
add_subdirectory(src)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
include_directories(${PROJECT_NAME} PUBLIC include)
target_link_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(  ${PROJECT_NAME} libsrc libscenes libmain_scene
    librenders libevents libutils ${SDL2_LIBRARIES} SDL2_image)
# NOTE THAT libfsm WAS REMOVED FROM LINKING
