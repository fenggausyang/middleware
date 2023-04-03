cmake_minimum_required(VERSION 3.22)
project( Main )

include_directories(../lib/opencv4/include)

link_directories(../lib/opencv4/lib)

file(GLOB OPENCV_LIBSB
    "${CMAKE_SOURCE_DIR}/../lib/opencv4/lib/*.so"
    "${CMAKE_SOURCE_DIR}/../lib/opencv4/lib/*.so.*"
)

set(LIST ./src/trainTest.cpp)

add_executable(main ${LIST})

target_link_libraries(main ${OPENCV_LIBSB})
