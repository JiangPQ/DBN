//
// Created by jiangpq on 17-10-6.
//
#include "Tensor.h"
#ifndef DBN_FLOAT_TENSOR_H
#define DBN_FLOAT_TENSOR_H


class FloatTensor:public Tensor {
private:
    float * storage;
public:
    FloatTensor(long int n_dimension, long int * dimensions);
    ~FloatTensor();
};


#endif //DBN_FLOAT_TENSOR_H
