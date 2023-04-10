# power_lib/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(power_library)

set(CMAKE_CXX_STANDARD 20)

add_library(power_lib  msr_reader.cpp rapl_reader.cpp)

target_include_directories(power_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
