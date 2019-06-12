cmake_minimum_required(VERSION 3.13.4)
project(graph_bridge)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph_bridge main.cpp graph.cpp graph.h unionfind1.cpp unionfind1.h unionfind2.cpp unionfind2.h)