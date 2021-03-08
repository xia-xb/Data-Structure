# 设置版本要求，工程名，类型，编译器
cmake_minimum_required(VERSION 3.1.0)
project(DATA-STRUCTURE)
set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-Wall -std=c++11)
set(CMAKE_CXX_COMPILE "D:/Programme/CPP/mingw-w64/mingw64/bin/g++")

# 添加文件夹
set(SDIR ${PROJECT_SOURCE_DIR})
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})
include_directories(${SRC_DIR})

# 生成可执行文件
set(SRC ${SRC_DIR}/main.cpp ${SRC_DIR}/graph.cpp)
add_executable(main ${SRC})

# 设置可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/)


