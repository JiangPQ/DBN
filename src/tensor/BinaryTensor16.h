//
// Created by AMOBBS on 2017/10/6.
//
#include "BaseTensor.h"
#include "BinaryTensor.h"

#ifndef DBN_BINARYTENSOR16_H
#define DBN_BINARYTENSOR16_H


class BinaryTensor16: public BinaryTensor {

private:
    unsigned short * storage;
    BinaryTensor16(long int n_dimension, long int * dimensions);
    ~BinaryTensor16();
};


#endif //DBN_BINARYTENSOR16_H
