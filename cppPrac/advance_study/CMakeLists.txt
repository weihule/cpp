cmake_minimum_required(VERSION 3.24)
project(advance_study)

set(CMAKE_CXX_STANDARD 17)

# 添加头文件
include_directories(include)

# 添加源文件 (DIR_SRCS 是 ./src 的别名)
aux_source_directory(./src DIR_SRCS)

# 所有需要编译的可执行文件
# ${DIR_SRCS} 表示 ./src文件夹下的所有源文件都需要编译
add_executable(advance_study ${DIR_SRCS} include/game1.h src/game1.cpp include/game2.h src/game2.cpp)
