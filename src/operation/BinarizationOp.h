//
// Created by jiangpq on 17-10-7.
//

#ifndef DBN_BINARIZATIONOP_H
#define DBN_BINARIZATIONOP_H


#include "BaseOperation.h"
#include "../tensor/FloatTensor.h"

class BinarizationOp: BaseOperation {
private:
public:
    BinaryTensor forward(FloatTensor input);
};


#endif //DBN_BINARIZATIONOP_H
