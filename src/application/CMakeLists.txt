include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(libapp application.cpp app_state.cpp
    title_state.cpp running_state.cpp paused_state.cpp)
