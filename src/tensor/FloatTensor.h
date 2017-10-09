//
// Created by jiangpq on 17-10-6.
//
#include "Tensor.h"
#ifndef DBN_FLOAT_TENSOR_H
#define DBN_FLOAT_TENSOR_H


class FloatTensor:public Tensor {
    friend class BinarizationOp8;

    friend class FloatenOp;
private:
    float * storage;
public:
    FloatTensor(long int n_dimension, long int * dimensions);
    ~FloatTensor() final;
};


#endif //DBN_FLOAT_TENSOR_H
