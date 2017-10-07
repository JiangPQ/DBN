//
// Created by AMOBBS on 2017/10/6.
//
#include "BaseTensor.h"
#ifndef DBN_BINARYTENSOR16_H
#define DBN_BINARYTENSOR16_H


class BinaryTensor16: public BaseTensor {

private:
    long int last_dim_len;
    unsigned short * storage;
public:
    BinaryTensor16(long int n_dimension, long int * dimensions);
    ~BinaryTensor16();
    long int get_actual_last_dim_len();
};


#endif //DBN_BINARYTENSOR16_H
