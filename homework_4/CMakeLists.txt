# minimum project options
project(hw3 LANGUAGES CXX)
cmake_minimum_required(VERSION 3.20)

# cpp version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ipb src/ipb.cpp)
add_library(algo src/algo.cpp)
add_executable(hw4 src/main.cpp)
target_link_libraries(hw4 ipb)
target_link_libraries(hw4 algo)

# Set build type if not set.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Export commands.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build flags.
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}cmake")
option(ENABLE_CPPCHECK "Enable static analysis with cppcheck" ON)
option(ENABLE_CLANG_TIDY "Enable static analysis with clang-tidy" ON)
option(ENABLE_COVERAGE "Enable coverage reporting" OFF)

