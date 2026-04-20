cmake_minimum_required(VERSION 3.15)
project(library)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 头文件目录（让编译器找到 include）
include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC_FILES
        ${PROJECT_SOURCE_DIR}/src/db.cpp
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/sqlite3.c
)

# 生成可执行文件
add_executable(library ${SRC_FILES})