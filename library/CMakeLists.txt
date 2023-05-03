cmake_minimum_required(VERSION 3.24)
project(library)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)
set(SQL_INC_DIR C:/Program\ Files/MySQL/MySQL\ Server\ 8.0/include)
set(SQL_LINK_DIR C:/Program\ Files/MySQL/MySQL\ Server\ 8.0/lib)

# 添加头文件
include_directories("${SQL_INC_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")

# 引入外部库，在当前项目的lib文件夹下
# link_directories("${PROJECT_SOURCE_DIR}/lib")
link_directories(${SQL_LINK_DIR})

#添加libmysql.lib静态库，编译和链接时需要用到它
link_libraries(libmysql)

# 设置dll_src为libmysql.dll的路径变量名，后面再使用libmysql.dll路径就可以使用缩写了
file(GLOB dll_src "${SQL_LINK_DIR}/libmysql.dll")

# 在生成可执行文件后将动态库libmysql.dll放入Bin目录下，在执行程序时会直接调用。
file(COPY ${dll_src} DESTINATION ${CMAKE_BINARY_DIR})

# 添加源文件
aux_source_directory(./src DIR_SRCS)

add_executable(library main.cpp src/crud.cpp include/crud.h)

#target_link_libraries(library
#        "${PROJECT_SOURCE_DIR}/lib/libmysql.lib")
target_link_libraries(library
        libmysql)
