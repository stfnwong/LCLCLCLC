# LCLCLCLC CMake config for unit tests
# 
# Stefan Wong 2020

include_directories(${TEST_SOURCE_DIR}/src)
# Just try one test for now
add_executable(test_tree test_tree.cpp)
