cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")
include_directories( ${MY_SOURCE_DIR}/ )
add_subdirectory(expressions)
add_executable(engine-app EngineApp.cpp)




