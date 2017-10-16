//
// Created by jiangpq on 17-10-16.
//

#include "BinAvgPooling2d.h"

int BinAvgPooling2d::forward(Binary8Tensor *input, int stride, int size, Binary8Tensor *output) {

    auto N = input->get_dimensions()[0];
    auto Cin = input->get_dimensions()[1];
    auto H = input->get_dimensions()[2];
    auto W = input->get_dimensions()[3];
    auto input_last_dim_len = input->get_actual_last_dim_len();
    auto input_storage = input->get_storage();

    auto Cout = output->get_dimensions()[1];
    auto output_H = output->get_dimensions()[2];
    auto output_W = output->get_dimensions()[3];

    auto output_last_dim_len = output->get_actual_last_dim_len();
    auto output_storage = output->get_storage();

    for (int batch = 0; batch < N; ++batch) {

        for (int ch_out = 0; ch_out < Cout; ++ch_out) {

            for (int ch_in = 0; ch_in < Cin; ++ch_in) {
                long input_base_idx = input_last_dim_len * H * (ch_in + batch * Cin);
                long output_base_idx = output_last_dim_len * output_H * (Cout * batch + ch_out);

                for (int row = 0; row < H; row += 2) {

                    for (int col = 0; col < ((W & 0x01) ? W : W + 1); col += 2) {
                        unsigned char temp = 0;
                        long input_idx = input_base_idx + input_last_dim_len * row + col / 8;
                        long output_idx = output_base_idx + output_last_dim_len * row / 2 + col / 2 / 8;

                        if (col / 8 == (col + 2) / 8) {
                            auto rem = (unsigned char) (col % 8);
                            temp |= (input_storage[input_idx] >> rem) & 0x03;
                            temp |= (rem < 2) ?
                                    ((input_storage[input_idx + input_last_dim_len] << 2) & 0x0A) :
                                    ((input_storage[input_idx + input_last_dim_len] >> (rem - 2)) & 0x0A);
                        } else {
                            temp |= (input_storage[input_idx] >> 7) & 0x01;
                            temp |= (input_storage[input_idx + input_last_dim_len] >> 5) & 0x04;

                            temp |= (input_storage[input_idx + 1] << 1) & 0x02;
                            temp |= (input_storage[input_idx + input_last_dim_len] << 3) & 0x08;
                        }

                        if (POPCNT4[temp] >= 2) {
                            output_storage[output_idx] |= 0x01 << ((col / 2) % 8);
                        } else {
                            output_storage[output_idx] &= 0xfe << ((col / 2) % 8);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
