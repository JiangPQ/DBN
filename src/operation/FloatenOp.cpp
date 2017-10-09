//
// Created by jiangpq on 17-10-9.
//

#include "FloatenOp.h"

/**
 * Convert a BinaryTensor to a FloatTensor, 1.0 for bit 1, -1.0 for bit 0.
 * @param input
 * @return
 */
FloatTensor *FloatenOp::forward(BinaryTensor8 *input) {
    auto *output = new FloatTensor(input->get_ndimension(), input->get_dimensions());

    long output_last_dim_len = output->get_dimensions()[input->get_ndimension() - 1];

    long last_dim_num = input->get_how_many_last_dim();
    long input_last_dim_len = input->get_actual_last_dim_len();

    for (int i = 0; i < last_dim_num; ++i) {
        long rem = output_last_dim_len % 8;
        long d = rem ? 1 : 0;

        for (int j = 0; j < input_last_dim_len - d; ++j) {
            long index = j + input_last_dim_len * i;

            for (int k = 0; k < 8; ++k)
                output->storage[k + 8 * index] = (input->storage[index] >> k) ? 1 : -1;
        }

        if (d) {
            long index = input_last_dim_len * (i + 1) - 1;

            for (int k = 0; k < rem; ++k)
                output->storage[k + 8 * index] = (input->storage[index] >> k) ? 1 : -1;
        }
    }
    return output;
}

FloatTensor *FloatenOp::forward(BinaryTensor16 *input) {
    return nullptr;
}
