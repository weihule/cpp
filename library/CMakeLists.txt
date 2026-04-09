cmake_minimum_required(VERSION 3.15)
project(LibrarySystem)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 头文件目录（让编译器找到 include）
include_directories(${PROJECT_SOURCE_DIR}/include)

# 自动收集所有 cpp
file(GLOB SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# 生成可执行文件
add_executable(Library ${SRC_FILES})