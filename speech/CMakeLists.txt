cmake_minimum_required(VERSION 3.24)
project(speech)

set(CMAKE_CXX_STANDARD 11)

add_executable(speech main.cpp speech_manager.cpp speech_manager.h speaker.h)
