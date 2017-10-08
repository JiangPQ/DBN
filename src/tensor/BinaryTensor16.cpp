//
// Created by AMOBBS on 2017/10/6.
//

#include "BinaryTensor16.h"

BinaryTensor16::BinaryTensor16(long n_dimension, const long * dimensions):
        BinaryTensor(n_dimension, dimensions) {

    long length = 1;
    for(long i = 0; i < n_dimension - 1; i++){
        length *= dimensions[i];
    }
    length *= this->get_actual_last_dim_len();
    this->storage = new unsigned short(length);
}

BinaryTensor16::~BinaryTensor16() {
    delete this->storage;
}
