cmake_minimum_required(VERSION 3.27)
project(ds_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(ds_cpp main.cpp
        LinkedList/LinkedList.cpp
        LinkedList/LinkedList.h)
