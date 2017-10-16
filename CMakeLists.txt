cmake_minimum_required(VERSION 3.8)
project(DBN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES example/main.cpp src/tensor/Tensor.cpp src/tensor/Tensor.h src/tensor/FloatTensor.cpp src/tensor/FloatTensor.h src/operation/BaseOperation.cpp src/operation/BaseOperation.h src/tensor/Binary8Tensor.cpp src/tensor/Binary8Tensor.h src/operation/Float2BinaryOp.cpp src/operation/Float2BinaryOp.h src/operation/Binary2FloatOp.cpp src/operation/Binary2FloatOp.h src/operation/BinConv2d.cpp src/operation/BinConv2d.h src/check_funcs.cpp src/check_funcs.h src/operation/BinAvgPooling2d.cpp src/operation/BinAvgPooling2d.h)
add_executable(DBN ${SOURCE_FILES})