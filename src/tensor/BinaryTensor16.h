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
public:
    BinaryTensor16(long n_dimension, const long * dimensions);
    ~BinaryTensor16();
};


#endif //DBN_BINARYTENSOR16_H
