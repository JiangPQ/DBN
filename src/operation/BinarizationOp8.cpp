//
// Created by jiangpq on 17-10-7.
//

#include "BinarizationOp8.h"

BinaryTensor8 * BinarizationOp8::forward(FloatTensor * input) {
    auto * output = new BinaryTensor8(input->get_ndimension(), input->get_dimensions());
    long index = 0;
    for(long i = 0; i < input->get_ndimension(); i++) {
        for (long j = 0; j < input->get_dimensions()[i]; ++j) {

        }
    }

    return output;
}
