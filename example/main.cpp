#include <iostream>
#include "../src/tensor/Binary8Tensor.h"
#include "../src/tensor/FloatTensor.h"
#include "../src/operation/Float2BinaryOp.h"
#include "../src/operation/BinConv2d.h"
#include "../src/operation/Binary2FloatOp.h"

int main() {

    std::cout << "test" << std::endl;

    long input_Nd = 4;
    long input_dims[4] = {1, 3, 256, 256};

    long weight_Nd = 4;
    long weight_dims[4] = {3, 10, 3, 3};

    long output_Nd = 4;
    long output_dims[4] = {1, 10, 254, 254};

    auto *tensor1 = new Binary8Tensor(input_Nd, input_dims);
    auto *weight = new Binary8Tensor(weight_Nd, weight_dims, true);
    auto *output = new Binary8Tensor(output_Nd, output_dims);

    BinConv2d().forward(tensor1, weight, output);

    std::cout << "n_dimensions = " << output->get_ndimension() << std::endl;
    std::cout << "actual last dim length = " << tensor1->get_actual_last_dim_len() << std::endl;
    std::cout << output->get_dimensions()[0] << ' '
              << output->get_dimensions()[1] << ' '
              << output->get_dimensions()[2] << ' '
              << output->get_dimensions()[3] << ' '
              << std::endl;
    delete tensor1;
    delete weight;
    delete output;

    return 0;
}