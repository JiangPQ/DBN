//
// Created by jiangpq on 17-10-7.
//

#include "BinaryTensor.h"

BinaryTensor::BinaryTensor(long n_dimension, long *dimensions) :
        BaseTensor(n_dimension, dimensions) {

}

long int BinaryTensor::get_actual_last_dim_len() {
    return this->last_dim_len;
}
