//
// Created by jiangpq on 17-10-7.
//

#ifndef DBN_BINARY8TENSOR_H
#define DBN_BINARY8TENSOR_H


#include "Tensor.h"

class Binary8Tensor : public Tensor {
    friend class Float2BinaryOp;

    friend class Binary2FloatOp;

    friend class BinConv2d;

private:
    long last_dim_len;
    long last_dim_num;
    bool is_weight;
    unsigned char *storage;
public:
    Binary8Tensor(long Nd, const long dimensions[], bool is_weight = false);

    ~Binary8Tensor() final;

    long get_actual_last_dim_len();

    long get_how_many_last_dim();

    bool get_is_weight();
};


#endif //DBN_BINARY8TENSOR_H
