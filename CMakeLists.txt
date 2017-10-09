cmake_minimum_required(VERSION 3.8)
project(DBN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES example/main.cpp src/tensor/Tensor.cpp src/tensor/Tensor.h src/tensor/FloatTensor.cpp src/tensor/FloatTensor.h src/operation/BaseOperation.cpp src/operation/BaseOperation.h src/tensor/BinaryTensor16.h src/tensor/BinaryTensor16.cpp src/tensor/BinaryTensor16.h src/tensor/BinaryTensor8.cpp src/tensor/BinaryTensor8.h src/operation/BinarizationOp8.cpp src/operation/BinarizationOp8.h src/tensor/BinaryTensor.cpp src/tensor/BinaryTensor.h src/operation/FloatenOp.cpp src/operation/FloatenOp.h)
add_executable(DBN ${SOURCE_FILES})