cmake_minimum_required(VERSION 3.24)
project(reservation)

set(CMAKE_CXX_STANDARD 20)

add_executable(reservation main.cpp identity.h persons.cpp persons.h global_file.h computer.h)
