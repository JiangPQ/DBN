//
// Created by jiangpq on 17-10-6.
//

#include "BaseTensor.h"

BaseTensor::BaseTensor(long n_dimension, const long * dimensions) {
    this->n_dimension = n_dimension;
    this->dimensions = new long(n_dimension);
    for(long i = 0; i < n_dimension; i++) {
        this->dimensions[i] = dimensions[i];
    }
}

BaseTensor::~BaseTensor() {
    delete this->dimensions;
}

long int BaseTensor::get_ndimension() {
    return this->n_dimension;
}

long int *BaseTensor::get_dimensions() {
    return this->dimensions;
}
