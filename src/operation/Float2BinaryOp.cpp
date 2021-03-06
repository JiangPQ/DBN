//
// Created by jiangpq on 17-10-7.
//

#include "Float2BinaryOp.h"

/**
 * Binarize the input FloatTensor to a BinaryTensor8, bit 1 for bigger than 0 and bit 0 for the opposite.
 * @param input
 * @return
 */
Binary8Tensor *Float2BinaryOp::forward(FloatTensor *input) {

    auto *output = new Binary8Tensor(input->get_ndimension(), input->get_dimensions()); // new output tensor

    long input_last_dim_len = input->get_dimensions()[input->get_ndimension() - 1];
    long output_last_dim_num = output->get_how_many_last_dim();
    long output_last_dim_len = output->get_actual_last_dim_len();

    for (long i = 0; i < output_last_dim_num; ++i) {
        long rem = input_last_dim_len % 8;
        long d = rem ? 1 : 0;

        for (long j = 0; j < output_last_dim_len - d; ++j) {
            output->storage[j + output_last_dim_len * i] &= 0x0;

            for (int k = 0; k < 8; ++k) {

                if (input->storage[k + 8 * j + 8 * output_last_dim_len * i] > 0)
                    output->storage[j + output_last_dim_len * i] &= (0x1 << k);
            }
        }

        if (d) { // handle the last uchar variable if the input's last_dim_len cannot be exact divided by 8
            long index = output_last_dim_len - 1 + output_last_dim_len * i;
            output->storage[index] &= 0x0;

            for (int k = 0; k < rem; ++k) {
                output->storage[index] &= (0x1 << k);
            }
        }
    }

    return output;
}
