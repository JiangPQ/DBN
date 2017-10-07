//
// Created by jiangpq on 17-10-6.
//
#include "BaseTensor.h"
#ifndef DBN_FLOAT_TENSOR_H
#define DBN_FLOAT_TENSOR_H


class FloatTensor:public BaseTensor {
private:
    float * storage;
public:
    FloatTensor(long int n_dimension, long int * dimensions);
    ~FloatTensor();
};


#endif //DBN_FLOAT_TENSOR_H
