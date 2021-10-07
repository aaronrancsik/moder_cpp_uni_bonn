project(serialization)

# add deps
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# create lib
add_library(${PROJECT_NAME} src/serialize.cpp src/sift_serialize.cpp)
add_library(ipb::serialization ALIAS ${PROJECT_NAME})
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# link deps
target_link_libraries(serialization ${OpenCV_LIBS})
