cmake_minimum_required(VERSION 3.8)
project(DBN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES example/main.cpp src/data_format/base_tensor.cpp src/data_format/base_tensor.h src/data_format/float_tensor.cpp src/data_format/float_tensor.h src/operation/base_operator.cpp src/operation/base_operator.h)
add_executable(DBN ${SOURCE_FILES})