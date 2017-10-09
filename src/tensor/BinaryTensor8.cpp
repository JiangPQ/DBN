//
// Created by jiangpq on 17-10-7.
//

#include "BinaryTensor8.h"

BinaryTensor8::BinaryTensor8(long n_dimension, const long *dimensions, bool is_weight = false) : Tensor(
        n_dimension, dimensions) {

    this->is_weight = is_weight;

    // compute how many last dimensions are there
    this->last_dim_num = 1;
    for (long i = 0; i < n_dimension - 1; ++i) {
        this->last_dim_num *= dimensions[i];
    }

    // compute the length the last dimension
    long rem = dimensions[n_dimension - 1] % 8;
    // if this tensor is a 3 by 3 weight, then cut it to length 8
    this->last_dim_len = dimensions[n_dimension - 1] / 8 + (!this->is_weight && rem >= 4) ? 1 : 0;

    this->storage = new unsigned char(this->last_dim_num * this->last_dim_len);
}

BinaryTensor8::~BinaryTensor8() {
    delete this->storage;
}

long BinaryTensor::get_actual_last_dim_len() {
    return this->last_dim_len;
}

long BinaryTensor::get_how_many_last_dim() {
    return this->last_dim_num;
}

bool BinaryTensor::get_is_weight() {
    return this->is_weight;
}
