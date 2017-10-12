//
// Created by jiangpq on 17-10-6.
//
#include "Tensor.h"
#ifndef DBN_FLOAT_TENSOR_H
#define DBN_FLOAT_TENSOR_H


struct FloatTensor : public Tensor {
    friend class Float2BinaryOp;

    friend class Binary2FloatOp;
private:
    float * storage;
public:
    FloatTensor(long int n_dimension, long int * dimensions);
    ~FloatTensor() final;
};


#endif //DBN_FLOAT_TENSOR_H
