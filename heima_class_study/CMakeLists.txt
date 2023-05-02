cmake_minimum_required(VERSION 3.24)
project(heima_class_study)

set(CMAKE_CXX_STANDARD 17)

# 添加头文件
include_directories(Headers)

# 添加源文件 (DIR_SRCS 是 ./src 的别名)
aux_source_directory(./Sources DIR_SRCS)

add_executable(heima_class_study ${DIR_SRCS})
