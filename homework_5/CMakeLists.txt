cmake_minimum_required(VERSION 3.20)
project(hw5)

# cpp version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# it's used by clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set build type if not set.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Build flags.
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
add_executable(main src/main.cpp)

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_library(mat_serialization src/serialize.cpp)
add_library(convert_dataset src/convert_dataset.cpp)

target_link_libraries(mat_serialization ${OpenCV_LIBS})
target_link_libraries(convert_dataset ${OpenCV_LIBS})
target_link_libraries(convert_dataset mat_serialization)
target_link_libraries(main ${OpenCV_LIBS})
target_link_libraries(main mat_serialization)
target_link_libraries(main convert_dataset)


# tests
# set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# include(TestCoverage)
# include(ClangFormat)
# include(StaticAnalyzers)

# subdirs(${CMAKE_SOURCE_DIR}/tests)