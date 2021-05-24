# minimum project options
project(hw4 LANGUAGES CXX)
cmake_minimum_required(VERSION 3.20)

# cpp version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(hw4 src/main.cpp)

add_library(ipb_algorithm src/ipb_algorithm.cpp)
target_link_libraries(hw4 ipb_algorithm)


# Set build type if not set.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()


# Export commands.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build flags.
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tests
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(TestCoverage)
include(ClangFormat)
include(StaticAnalyzers)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

subdirs(${CMAKE_SOURCE_DIR}/tests)