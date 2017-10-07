//
// Created by jiangpq on 17-10-7.
//

#ifndef DBN_BINARYTENSOR8_H
#define DBN_BINARYTENSOR8_H


#include "BaseTensor.h"

class BinaryTensor8: public BaseTensor {
private:
    long int last_dim_len;
    unsigned char * storage;
    BinaryTensor8(long int n_dimension, long int * dimensions);
    ~BinaryTensor8();
public:
    long int get_actual_last_dim_len();
};


#endif //DBN_BINARYTENSOR8_H
