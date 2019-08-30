# 声明需要的cmake最小版本为2.8
cmake_minimum_required(VERSION 2.8)
# 声明cmake工程
project(Eigen)
# 设置编译模式为发布模式
set(CMAKE_BUILD_TYPE "Release")
# 设置编译参数
set(CMAKE_CXX_FLAGS "-O3")
# 添加Eigen头文件
include_directories("/usr/local/include/eigen3")
# 添加一个可执行程序
add_executable(TestEigen TestEigen.cpp)
