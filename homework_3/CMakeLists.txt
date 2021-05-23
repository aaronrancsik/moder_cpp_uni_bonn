cmake_minimum_required(VERSION 3.10)
project(hw3) 

# Set build type if not set.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Build options.
option(ENABLE_CPPCHECK "Enable static analysis with cppcheck" ON)
option(ENABLE_CLANG_TIDY "Enable static analysis with clang-tidy" ON)
option(ENABLE_COVERAGE "Enable coverage reporting" OFF)

# Standard version.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Export commands.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build flags.
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Import cmake modules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")



set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Main 
add_executable(hw3 ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_include_directories(hw3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# My lib and dependencies

find_package(fmt REQUIRED)

add_library(html_writer STATIC src/html_writer.cpp)
target_link_libraries(html_writer PUBLIC fmt::fmt) 

add_library(image_browser STATIC src/image_browser.cpp)
target_link_libraries(image_browser PUBLIC fmt::fmt)
target_link_libraries(image_browser PUBLIC html_writer)

target_link_libraries(hw3 PUBLIC html_writer)
target_link_libraries(hw3 PUBLIC image_browser)