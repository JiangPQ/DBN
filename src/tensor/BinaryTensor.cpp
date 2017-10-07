//
// Created by jiangpq on 17-10-7.
//

#include "BinaryTensor.h"

BinaryTensor::BinaryTensor(long n_dimension, long *dimensions) :
        BaseTensor(n_dimension, dimensions) {

    this->last_dim_len = int(dimensions[n_dimension - 1] / 8);
    if(dimensions[n_dimension - 1] % 8)
        this->last_dim_len += 1;
}

long int BinaryTensor::get_actual_last_dim_len() {
    return this->last_dim_len;
}
