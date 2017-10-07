//
// Created by AMOBBS on 2017/10/6.
//

#include "BinaryTensor16.h"

BinaryTensor16::BinaryTensor16(long int n_dimension, long int *dimensions):
        BaseTensor(n_dimension, dimensions) {
    this->last_dim_len = int(dimensions[n_dimension - 1] / 8);
    if(dimensions[n_dimension - 1] % 8)
        this->last_dim_len += 1;
    long int length = 1;
    for(int i = 0; i < n_dimension; i++){
        length *= dimensions[i];
    }
    this->storage = new unsigned short(length);
}

BinaryTensor16::~BinaryTensor16() {
    delete this->storage;
}

long int BinaryTensor16::get_actual_last_dim_len() {
    return this->last_dim_len;
}
