//
// Created by jiangpq on 17-10-7.
//

#ifndef DBN_BINARIZATIONOP_H
#define DBN_BINARIZATIONOP_H


#include "BaseOperation.h"
#include "../tensor/FloatTensor.h"
#include "../tensor/Binary8Tensor.h"

class Float2BinaryOp : public BaseOperation {
public:
    Binary8Tensor *forward(FloatTensor *input);
};


#endif //DBN_BINARIZATIONOP_H
