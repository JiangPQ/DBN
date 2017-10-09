//
// Created by jiangpq on 17-10-9.
//

#include "BinConv2d.h"

BinaryTensor8 *BinConv2d::forward(BinaryTensor8 *input, BinaryTensor8 *weight) {
    auto N = input->get_dimensions()[0];
    auto H = input->get_dimensions()[2];
    auto W = input->get_dimensions()[3];
    auto Cout = weight->get_dimensions()[0];
    auto k_size0 = weight->get_dimensions()[2];
    auto k_size1 = weight->get_dimensions()[3];

    auto n_dimension = input->get_ndimension();
    auto *dimensions = new long[4];
    dimensions[0] = N;
    dimensions[1] = Cout;
    dimensions[2] = H - k_size0 + 1;
    dimensions[3] = W - k_size1 + 1;

    auto *output = new BinaryTensor8(n_dimension, dimensions);


    return output;
}

BinaryTensor16 *BinConv2d::forward(BinaryTensor16 *input, BinaryTensor16 *weight) {
    return nullptr;
}
