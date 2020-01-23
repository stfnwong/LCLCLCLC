# LCLCLCLC CMake config
# 
# Stefan Wong 2020

cmake_minimum_required(VERSION 2.8)
project(LCLCLCLC)
add_subdirectory(src)

enable_testing()
add_subdirectory(test)
