//
// Created by jiangpq on 17-10-6.
//

#include "FloatTensor.h"

FloatTensor::FloatTensor(long int n_dimension, long int * dimensions):
        BaseTensor(n_dimension, dimensions) {
    long int length = 1;
    for(int i = 0; i < n_dimension; i++){
        length *= dimensions[i];
    }
    this->storage = new float(length);
}

FloatTensor::~FloatTensor() {
    delete this->storage;
}
