cmake_minimum_required(VERSION 3.24)
project(new_proj)

# 最高支持C++17
set(CMAKE_CXX_STANDARD 17)

# 添加头文件
include_directories(include)

# 添加源文件 (DIR_SRCS 是 ./src 的别名)
aux_source_directory(./src DIR_SRCS)

message(${PROJECT_NAME})			# 项目名称
message(${PROJECT_BINARY_DIR})		# 项目的二进制目录，即编译后的可执行文件和库文件的输出目录
message(${PROJECT_SOURCE_DIR})		# 项目的源文件目录，即包含CMakeLists.txt文件的目录
message(${CMAKE_BINARY_DIR})
message(${CMAKE_SYSTEM_NAME})
message(${CMAKE_SYSTEM_PROCESSOR})
message(${CMAKE_CXX_COMPILER_ID})

set(var 123456)
message(${var})

# 所有需要编译的可执行文件
# ${DIR_SRCS} 表示 ./src文件夹下的所有源文件都需要编译
# add_executable(new_proj ${DIR_SRCS})
add_executable(new_proj myArray.cpp)
