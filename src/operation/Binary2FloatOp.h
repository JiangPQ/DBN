//
// Created by jiangpq on 17-10-9.
//

#ifndef DBN_FLOATENOP_H
#define DBN_FLOATENOP_H


#include "../tensor/FloatTensor.h"
#include "../tensor/Binary8Tensor.h"
#include "BaseOperation.h"

class Binary2FloatOp : public BaseOperation {
public:
    FloatTensor *forward(Binary8Tensor *input);
};


#endif //DBN_FLOATENOP_H
