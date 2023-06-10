project(world-gen)
cmake_minimum_required(VERSION 3.16)
set_property(GLOBAL PROPERTY CXX_STANDARD C++17)

add_executable(${PROJECT_NAME} app.cpp)
add_subdirectory(src)
include_directories(${PROJECT_NAME} PUBLIC include)
target_link_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} srclib)
