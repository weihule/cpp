cmake_minimum_required(VERSION 3.24)
project(new_proj)

# 最高支持C++17
set(CMAKE_CXX_STANDARD 17)

# 输出编译信息
message("Hello hl!!! Start compile!")

# 添加头文件
include_directories(include)

# 添加源文件 (DIR_SRCS 是 ./src 的别名)
aux_source_directory(./src DIR_SRCS)

# 所有需要编译的可执行文件
# ${DIR_SRCS} 表示 ./src文件夹下的所有源文件都需要编译
# add_executable(new_proj ${DIR_SRCS})
add_executable(new_proj myArray.cpp)
