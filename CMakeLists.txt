# CMakeLists.txt
cmake_minimum_required(VERSION 3.25)

# 设置项目名称
project(Middleware)

# 设置编译器标志
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# 添加cpr头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/cpr-master/include)

# 添加LocationService头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 添加json头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/jsoncpp/include)

# 添加OpenCV头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv4/include)

# 添加jsoncpp库文件的路径
add_subdirectory(lib/jsoncpp)
# 添加cpr库文件的路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/cpr-master/build/lib)
# 添加OpenCV库文件的路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv4/lib)

# 添加你的可执行文件
add_executable(main main.cpp src/LocationService.cpp src/Connector.cpp src/LocationCache.cpp)

# 链接cpr库
target_link_libraries(main cpr jsoncpp_lib)