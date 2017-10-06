cmake_minimum_required(VERSION 3.8)
project(DBN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES example/main.cpp)
add_executable(DBN ${SOURCE_FILES})