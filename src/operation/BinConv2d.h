//
// Created by jiangpq on 17-10-9.
//

#ifndef DBN_BINCONV2D_H
#define DBN_BINCONV2D_H


#include "BaseOperation.h"
#include "../tensor/BinaryTensor8.h"
#include "../tensor/BinaryTensor16.h"

class BinConv2d : public BaseOperation {
public:
    BinaryTensor8 *forward(BinaryTensor8 *input, BinaryTensor8 *weight);

    BinaryTensor16 *forward(BinaryTensor16 *input, BinaryTensor16 *weight);
};


#endif //DBN_BINCONV2D_H
