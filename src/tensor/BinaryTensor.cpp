//
// Created by jiangpq on 17-10-7.
//

#include "BinaryTensor.h"

BinaryTensor::BinaryTensor(long n_dimension, const long *dimensions, bool is_weight = false) :
        Tensor(n_dimension, dimensions) {
    this->is_weight = is_weight;
    this->last_dim_len = dimensions[n_dimension - 1] / 8;
    if(dimensions[n_dimension - 1] % 8)
        this->last_dim_len += 1;
    this->last_dim_num = 1;
    for (long i = 0; i < n_dimension - 1; ++i) {
        this->last_dim_num *= dimensions[i];
    }
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
