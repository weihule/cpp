cmake_minimum_required(VERSION 3.24)
project(stl_study)

set(CMAKE_CXX_STANDARD 17)

add_executable(stl_study main.cpp test.cpp test.h person.hpp custom_array.hpp)
