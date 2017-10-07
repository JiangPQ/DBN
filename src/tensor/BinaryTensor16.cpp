//
// Created by AMOBBS on 2017/10/6.
//

#include "BinaryTensor16.h"

BinaryTensor16::BinaryTensor16(long int n_dimension, long int *dimensions):
        BinaryTensor(n_dimension, dimensions) {

    long int length = 1;
    for(int i = 0; i < n_dimension; i++){
        length *= dimensions[i];
    }

    this->storage = new unsigned short(length);
}

BinaryTensor16::~BinaryTensor16() {
    delete this->storage;
}
