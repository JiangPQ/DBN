//
// Created by jiangpq on 17-10-7.
//

#include "BinaryTensor8.h"

BinaryTensor8::BinaryTensor8(long int n_dimension, long int *dimensions):
        BinaryTensor(n_dimension, dimensions) {

    long int length = 1;
    for(int i = 0; i < n_dimension; i++){
        length *= dimensions[i];
    }
    this->storage = new unsigned char(length);
}

BinaryTensor8::~BinaryTensor8() {
    delete this->storage;
}

