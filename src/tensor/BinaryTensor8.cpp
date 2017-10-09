//
// Created by jiangpq on 17-10-7.
//

#include "BinaryTensor8.h"

BinaryTensor8::BinaryTensor8(long n_dimension, const long *dimensions, bool is_weight = false) : BinaryTensor(
        n_dimension, dimensions, is_weight) {

    long int length = 1;
    for(int i = 0; i < n_dimension - 1; i++){
        length *= dimensions[i];
    }
    length *= this->get_actual_last_dim_len();
    this->storage = new unsigned char(length);
}

BinaryTensor8::~BinaryTensor8() {
    delete this->storage;
}

