cmake_minimum_required(VERSION 2.8)
find_package(Boost 1.53.0 REQUIRED)
include_directories(SYSTEM "${Boost_INCLUDE_DIRS}")

# Make sure gen-cpp files can be included
message("hao :CMAKE_CURRENT_BINARY_DIR --> ${CMAKE_CURRENT_BINARY_DIR}")
message("hao :PROJECT_SOURCE_DIR --> ${PROJECT_SOURCE_DIR}")

#SET(CMAKE_CXX_FLAGS "-g -O3 -flto -Dlinux -std=c++11 -lboost_locale -w -fpermissive -Wl,--export-dynamic -Wno-deprecated")
SET(CMAKE_CXX_FLAGS "-g -O3 -flto -Dlinux -std=c++11  -w -fpermissive -Wl,--export-dynamic -Wno-deprecated")
add_definitions(
    -DMUDUO_STD_STRING
    -DHAVE_NETINET_IN_H
    -DMUDUO_LOG
    )
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/gen-cpp")
include_directories("${PROJECT_SOURCE_DIR}/lib/cpp/src")
include_directories("/usr/local/thrift/include/thrift")

# include(ThriftMacros)

# 源码集合
set(demo_SOURCES 
  demo_server.cpp
  gen-cpp/UserStorage.cpp
  gen-cpp/demo_types.cpp
  gen-cpp/demo_constants.cpp
  )

# 生成静态库目标
add_library(demo STATIC ${demo_SOURCES})
target_link_libraries(demo thrift)

# 同下
add_executable(demo_server demo_server.cpp)
target_link_libraries(demo_server demo)
target_link_libraries(demo_server thrift)

# 生成 demo_client 可执行程序，要求链接 demo 静态库, thrift XX库
add_executable(demo_client demo_client.cpp)
target_link_libraries(demo_client demo)
target_link_libraries(demo_client thrift)
