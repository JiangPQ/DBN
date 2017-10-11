//
// Created by jiangpq on 17-10-7.
//

#include "BinaryTensor8.h"

BinaryTensor8::BinaryTensor8(long n_dimension, const long *dimensions, bool is_weight) : Tensor(
        n_dimension, dimensions) {

    this->is_weight = is_weight;

    if (is_weight) {

        // compute how many last dimensions are there
        this->last_dim_num = 1;
        for (long dim = 0; dim < n_dimension - 3; ++dim) {
            this->last_dim_num *= dimensions[dim];
        }
        if (dimensions[n_dimension - 1] == 3 && dimensions[n_dimension - 2] == 3)
            this->last_dim_len = dimensions[n_dimension - 3];
    } else {

        // compute how many last dimensions are there
        this->last_dim_num = 1;
        for (long dim = 0; dim < n_dimension - 1; ++dim) {
            this->last_dim_num *= dimensions[dim];
        }

        // compute the length the last dimension
        long rem = dimensions[n_dimension - 1] % 8;
        this->last_dim_len = dimensions[n_dimension - 1] / 8 + (rem != 0) ? 1 : 0;
    }

    this->storage = new unsigned char[this->last_dim_num * this->last_dim_len];
}

BinaryTensor8::~BinaryTensor8() {
    delete this->storage;
}

long BinaryTensor8::get_actual_last_dim_len() {
    return this->last_dim_len;
}

long BinaryTensor8::get_how_many_last_dim() {
    return this->last_dim_num;
}

bool BinaryTensor8::get_is_weight() {
    return this->is_weight;
}
