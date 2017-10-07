cmake_minimum_required(VERSION 3.8)
project(DBN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES example/main.cpp src/tensor/BaseTensor.cpp src/tensor/BaseTensor.h src/tensor/FloatTensor.cpp src/tensor/FloatTensor.h src/operation/BaseOperation.cpp src/operation/BaseOperation.h src/tensor/BinaryTensor.h src/tensor/BinaryTensor.cpp src/tensor/BinaryTensor.h)
add_executable(DBN ${SOURCE_FILES})