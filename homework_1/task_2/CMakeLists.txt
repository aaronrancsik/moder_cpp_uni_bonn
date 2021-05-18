cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(task2 VERSION 1.0)

add_executable(task2 src/main.cpp)
target_include_directories(task2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(sub STATIC src/subtract.cpp)
add_library(sum STATIC src/sum.cpp)
target_include_directories(sum PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(sub PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(task2 PUBLIC sub)
target_link_libraries(task2 PUBLIC sum)