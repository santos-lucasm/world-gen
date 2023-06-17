project(world-gen)
cmake_minimum_required(VERSION 3.16)
set_property(GLOBAL PROPERTY CXX_STANDARD C++17)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -pthread")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -pthread")

find_package(SDL2 REQUIRED)
add_executable(${PROJECT_NAME} app.cpp)
add_subdirectory(src)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${PROJECT_NAME} PUBLIC include)
target_link_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} srclib ${SDL2_LIBRARIES})
