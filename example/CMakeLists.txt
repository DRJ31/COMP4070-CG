cmake_minimum_required(VERSION 3.13)
project(cg)

set(CMAKE_CXX_STANDARD 11)

add_executable(cg main.cpp ObjLoader.cpp)

target_link_libraries(cg GL glut)