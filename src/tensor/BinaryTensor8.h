//
// Created by jiangpq on 17-10-7.
//

#ifndef DBN_BINARYTENSOR8_H
#define DBN_BINARYTENSOR8_H


#include "Tensor.h"
#include "BinaryTensor.h"

class BinaryTensor8 : public Tensor {
    friend class BinarizationOp8;
    friend class FloatenOp;

    friend class BinConv2d;
private:
    long last_dim_len;
    long last_dim_num;
    bool is_weight;
    unsigned char * storage;
public:
    BinaryTensor8(long n_dimension, const long *dimensions, bool is_weight = false);
    ~BinaryTensor8() final ;

    long get_actual_last_dim_len();

    long get_how_many_last_dim();

    bool get_is_weight();
};


#endif //DBN_BINARYTENSOR8_H
