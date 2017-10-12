//
// Created by jiangpq on 17-10-9.
//

#include "BinConv2d.h"


/**
 * Binary Conv2d
 * @param input
 * @param weight
 * @return
 */
Binary8Tensor *BinConv2d::forward(Binary8Tensor *input, Binary8Tensor *weight, Binary8Tensor *output) {

    auto N = input->get_dimensions()[0];
    auto Cin = input->get_dimensions()[1];
    auto H = input->get_dimensions()[2];
    auto W = input->get_dimensions()[3];
    auto input_last_dim_len = input->get_actual_last_dim_len();

    auto Cout = weight->get_dimensions()[0];
    auto k_size0 = weight->get_dimensions()[2];
    auto k_size1 = weight->get_dimensions()[3];

    auto n_dimension = input->get_ndimension();

    auto output_last_dim_len = output->get_actual_last_dim_len();

    long row_max = H - k_size0 + 1;
    long col_max = W - k_size0 + 1;
    // flatten the input matrix
    for (int batch = 0; batch < N; ++batch) {

        for (int ch_out = 0; ch_out < Cout; ++ch_out) {

            for (int ch_in = 0; ch_in < Cin; ++ch_in) {
                long input_base_idx = input_last_dim_len * H * (Cin * batch + ch_in);
                long weight_base_idx = Cin * Cout;
                long output_base_idx = output_last_dim_len * row_max * (Cout * batch + ch_out);

                for (int row = 0; row < row_max; ++row) {

                    for (int col = 0; col < col_max; ++col) {
                        unsigned char temp = 0;
                        long input_idx = input_base_idx + input_last_dim_len * row + col / 8 + 1;
                        long output_idx = output_base_idx + output_last_dim_len * row + col / 8 + 1;

                        // if in the same byte
                        if (col / 8 == (col + 2) / 8) {
                            auto rem = (unsigned char) (col % 8);
                            temp |= (input->storage[input_idx] & (0x07 << rem)) >> rem;
                            temp |= rem > 3 ?
                                    (input->storage[input_idx + input_last_dim_len] & (0x07 << rem)) << (3 - rem) :
                                    (input->storage[input_idx + input_last_dim_len] & (0x07 << rem)) >> (rem - 3);
                            temp |= (input->storage[input_idx + input_last_dim_len * 2] & (0x03 << rem)) << (6 - rem);

                        } else {

                            if ((col + 2) % 8 == 1) {
                                temp |= (input->storage[input_idx] >> 6) & 0x03;
                                temp |= (input->storage[input_idx + 1] << 2) & 0x04;

                                temp |= (input->storage[input_idx + input_last_dim_len] >> 3) & 0x18;
                                temp |= (input->storage[input_idx + input_last_dim_len + 1] << 5) & 0x20;

                                temp |= input->storage[input_idx + input_last_dim_len * 2] & 0xC0;

                            } else {
                                temp |= (input->storage[input_idx] >> 7) & 0x01;
                                temp |= (input->storage[input_idx + 1] << 1) & 0x06;

                                temp |= (input->storage[input_idx + input_last_dim_len] >> 4) & 0x18;
                                temp |= (input->storage[input_idx + input_last_dim_len + 1] << 4) & 0x20;

                                temp |= (input->storage[input_idx + input_last_dim_len * 2] >> 1) & 0x40;
                                temp |= (input->storage[input_idx + input_last_dim_len * 2] << 7) & 0x80;
                            }
                        }

                        // apply popcnt to the result of binary convolution
                        if (POPCNT8[~(temp ^ weight->storage[weight_base_idx + ch_in])] >= 4) {
                            output->storage[output_idx] |= 0x1 << (col % 8);
                        } else {
                            output->storage[output_idx] &= 0xfe << (col % 8);
                        }
                    }
                }
            }
        }
    }
    return output;
}
