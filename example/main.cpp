#include <iostream>
#include "../src/tensor/Binary8Tensor.h"
#include "../src/tensor/FloatTensor.h"
#include "../src/operation/Float2BinaryOp.h"
#include "../src/operation/BinConv2d.h"
#include "../src/operation/Binary2FloatOp.h"

int main() {

    std::cout << "test" << std::endl;

    long input_Nd = 4;
    long input_dims[4] = {1, 3, 258, 258};

    long weight_Nd = 4;
    long weight_dims[4] = {3, 10, 3, 3};

    long output_Nd = 4;
    long output_dims[4] = {1, 10, 256, 256};

    auto *tensor1 = new Binary8Tensor(input_Nd, input_dims);
    auto *weight = new Binary8Tensor(weight_Nd, weight_dims, true);
    auto *output = new Binary8Tensor(output_Nd, output_dims);

    BinConv2d().forward(tensor1, weight, output);

    std::cout << "n_dimensions = " << output->get_ndimension() << std::endl;
    std::cout << "actual last dim length = " << output->get_actual_last_dim_len() << std::endl;
    std::cout << (int) output->get_storage()[0] << ' '
              << (int) output->get_storage()[1] << ' '
              << (int) output->get_storage()[2] << ' '
              << (int) output->get_storage()[3] << ' '
              << (int) output->get_storage()[4] << ' '
              << (int) output->get_storage()[5] << ' '
              << (int) output->get_storage()[6] << ' '
              << (int) output->get_storage()[7] << ' '
              << (int) output->get_storage()[8] << ' '
              << (int) output->get_storage()[9] << ' '
              << (int) output->get_storage()[10] << ' '
              << (int) output->get_storage()[11] << ' '
              << (int) output->get_storage()[12] << ' '
              << (int) output->get_storage()[13] << ' '
              << (int) output->get_storage()[14] << ' '
              << (int) output->get_storage()[15] << ' '
              << std::endl;
    delete tensor1;
    delete weight;
    delete output;

    return 0;
}