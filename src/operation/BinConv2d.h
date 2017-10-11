//
// Created by jiangpq on 17-10-9.
//

#ifndef DBN_BINCONV2D_H
#define DBN_BINCONV2D_H


#include "BaseOperation.h"
#include "../tensor/BinaryTensor8.h"

static unsigned char POPCNT[] = {};

class BinConv2d : public BaseOperation {
public:
    BinaryTensor8 *forward(BinaryTensor8 *input, BinaryTensor8 *weight);
};


#endif //DBN_BINCONV2D_H
