//
// Created by jiangpq on 17-10-7.
//

#ifndef DBN_BINARYTENSOR_H
#define DBN_BINARYTENSOR_H


#include "Tensor.h"

class BinaryTensor: public Tensor {
private:
    long int last_dim_len;
public:
    BinaryTensor(long n_dimension, const long * dimensions);
    virtual ~BinaryTensor() = 0;
    long int get_actual_last_dim_len();

};


#endif //DBN_BINARYTENSOR_H
