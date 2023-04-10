# CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(power_test)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(power_library)

add_executable(power_test main.cpp)
target_link_libraries(power_test power_lib)
