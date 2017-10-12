//
// Created by jiangpq on 17-10-7.
//

#include "Binary8Tensor.h"

Binary8Tensor::Binary8Tensor(long Nd, const long dimensions[], bool is_weight) : Tensor(
        4, dimensions) {
    this->is_weight = is_weight;

    if (is_weight) {

        if (dimensions[Nd - 1] == 3 && dimensions[Nd - 2] == 3) {
            this->last_dim_len = dimensions[Nd - 3];
            // compute how many last dimensions are there
            this->last_dim_num = 1;
            for (long dim = 0; dim < Nd - 3; ++dim) {
                this->last_dim_num *= dimensions[dim];
            }
        }
    } else {

        // compute how many last dimensions are there
        this->last_dim_num = 1;
        for (long dim = 0; dim < Nd - 1; ++dim) {
            this->last_dim_num *= dimensions[dim];
        }

        // compute the length the last dimension
        long rem = dimensions[Nd - 1] % 8;
        long fac = dimensions[Nd - 1] / 8;
        this->last_dim_len = fac + ((rem != 0) ? 1 : 0);
    }

    this->storage = new unsigned char[this->last_dim_num * this->last_dim_len];
}

Binary8Tensor::~Binary8Tensor() {
    delete[] this->storage;
}

long Binary8Tensor::get_actual_last_dim_len() {
    return this->last_dim_len;
}

long Binary8Tensor::get_how_many_last_dim() {
    return this->last_dim_num;
}

bool Binary8Tensor::get_is_weight() {
    return this->is_weight;
}
