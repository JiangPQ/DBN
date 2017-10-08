//
// Created by jiangpq on 17-10-7.
//

#ifndef DBN_BINARYTENSOR8_H
#define DBN_BINARYTENSOR8_H


#include "Tensor.h"
#include "BinaryTensor.h"

class BinaryTensor8: public BinaryTensor {
    friend class BinarizationOp8;
private:
    unsigned char * storage;
public:
    BinaryTensor8(long n_dimension, const long * dimensions);
    ~BinaryTensor8() final ;
};


#endif //DBN_BINARYTENSOR8_H
