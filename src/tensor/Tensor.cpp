//
// Created by jiangpq on 17-10-6.
//

#include "Tensor.h"

Tensor::Tensor(long n_dimension, const long * dimensions) {
    this->n_dimension = n_dimension;
    this->dimensions = new long[n_dimension];
    for(long i = 0; i < n_dimension; i++) {
        this->dimensions[i] = dimensions[i];
    }
}

Tensor::~Tensor() {
    delete this->dimensions;
}

long Tensor::get_ndimension() {
    return this->n_dimension;
}

long *Tensor::get_dimensions() {
    return this->dimensions;
}

long Tensor::get_length() {
    long length = 1;
    for (long i = 0; i < n_dimension; ++i) {
        length *= dimensions[i];
    }
    return length;
}
