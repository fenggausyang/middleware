# CMakeLists.txt
cmake_minimum_required(VERSION 3.25)

# 设置项目名称
project(MiddleWare)

# 设置编译器标志
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")


# 添加LBS头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/LBS)
# 添加COM头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/COM)
# 添加CS头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/CS)



# 添加cpr头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/cpr/include)
# 添加json头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/jsoncpp/include)
# 添加OpenCV头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv4/include)
# 添加paho cpp头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/paho.mqtt.cpp/install/include)
# 添加paho c头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/paho.mqtt.c/install/include)



# 添加jsoncpp库文件的路径
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/jsoncpp)
# 添加cpr库文件的路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/cpr/build/lib)
# 添加OpenCV库文件的路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv4/lib)
# 添加paho c库文件路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/paho.mqtt.c/install/lib)
# 添加paho cpp库文件的路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/paho.mqtt.cpp/install/lib)

# 添加OpenCV库文件
file(GLOB OPENCV_LIBS 
    "${CMAKE_SOURCE_DIR}/lib/opencv4/lib/*.so"
    "${CMAKE_SOURCE_DIR}/lib/opencv4/lib/*.so.*"
)

# 添加你的可执行文件
add_executable(main main.cpp src/LocationService.cpp src/Connector.cpp src/LocationCache.cpp)

# 链接cpr库
target_link_libraries(main cpr jsoncpp_lib)