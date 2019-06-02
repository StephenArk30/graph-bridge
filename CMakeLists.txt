cmake_minimum_required(VERSION 3.14)
project(graph_bridge)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph_bridge main.cpp graph.cpp graph.h unionfind.cpp unionfind.h)