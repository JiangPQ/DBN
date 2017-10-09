//
// Created by jiangpq on 17-10-7.
//

#ifndef DBN_BINARYTENSOR_H
#define DBN_BINARYTENSOR_H


#include "Tensor.h"

class BinaryTensor: public Tensor {
private:
    long last_dim_len;
    long last_dim_num;
    bool is_weight;
public:
    BinaryTensor(long n_dimension, const long *dimensions, bool is_weight = false);
    virtual ~BinaryTensor() = 0;

    long get_actual_last_dim_len();
    long get_how_many_last_dim();

    bool get_is_weight();

};


#endif //DBN_BINARYTENSOR_H
