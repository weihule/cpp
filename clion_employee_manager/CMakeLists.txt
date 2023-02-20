cmake_minimum_required(VERSION 3.24)
project(clion_employee_manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(clion_employee_manager main.cpp worker.h worker.cpp worker_manager.h worker_manager.cpp)
