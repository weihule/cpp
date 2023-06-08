cmake_minimum_required(VERSION 3.24)
project(reservation2)

set(CMAKE_CXX_STANDARD 17)

# 输出编译信息
message("Hello hl!!! Start compile!")

# 添加头文件
include_directories(include)

# 添加源文件
aux_source_directory(./src DIR_SRCS)

add_executable(reservation2 ${DIR_SRCS})
