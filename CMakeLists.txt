cmake_minimum_required(VERSION 3.8)
project(DBN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES example/main.cpp src/tensor/BaseTensor.cpp src/tensor/BaseTensor.h src/tensor/FloatTensor.cpp src/tensor/FloatTensor.h src/operation/base_operation.cpp src/operation/base_operation.h src/tensor/BinaryTensor.h src/tensor/BinaryTensor.cpp src/tensor/BinaryTensor.h)
add_executable(DBN ${SOURCE_FILES})