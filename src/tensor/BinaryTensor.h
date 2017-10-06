//
// Created by AMOBBS on 2017/10/6.
//
#include "BaseTensor.h"
#ifndef DBN_BINARYTENSOR_H
#define DBN_BINARYTENSOR_H


class BinaryTensor: public BaseTensor {

private:
    long int last_dim_len;
    short * storage;
public:
    BinaryTensor(long int n_dimension, long int * dimensions);
    long int get_actual_last_dim_len();
};


#endif //DBN_BINARYTENSOR_H
