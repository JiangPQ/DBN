//
// Created by jiangpq on 17-10-6.
//

#include "BaseTensor.h"

BaseTensor::BaseTensor(long int n_dimension, long int* dimensions) {
    this->n_dimension = n_dimension;
    this->dimensions = dimensions;
}

long int BaseTensor::get_ndimension() {
    return this->n_dimension;
}

long int *BaseTensor::get_dimensions() {
    return this->dimensions;
}
