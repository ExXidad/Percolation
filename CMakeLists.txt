cmake_minimum_required(VERSION 3.15)
project(maze)

set(CMAKE_CXX_STANDARD 14)

add_executable(maze main.cpp head.h doGraphics.cpp percolation.h percolation.cpp myTypes.h myTypes.cpp)

target_link_libraries(maze -lsfml-graphics -lsfml-window -lsfml-system )
