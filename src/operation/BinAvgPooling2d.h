//
// Created by jiangpq on 17-10-16.
//

#ifndef DBN_BINAVGPOOLING2D_H
#define DBN_BINAVGPOOLING2D_H


#include "BaseOperation.h"
#include "../tensor/Binary8Tensor.h"

static unsigned char POPCNT4[16] = {
        0, 1, 1, 2,
        1, 2, 2, 3,
        1, 2, 2, 3,
        2, 3, 3, 4
};

class BinAvgPooling2d : public BaseOperation {
public:
    int forward(Binary8Tensor *input, int stride, int size, Binary8Tensor *output);
};


#endif //DBN_BINAVGPOOLING2D_H
