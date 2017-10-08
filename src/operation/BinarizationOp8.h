//
// Created by jiangpq on 17-10-7.
//

#ifndef DBN_BINARIZATIONOP_H
#define DBN_BINARIZATIONOP_H


#include "BaseOperation.h"
#include "../tensor/FloatTensor.h"
#include "../tensor/BinaryTensor8.h"

class BinarizationOp8: BaseOperation {
private:
public:
    BinaryTensor8 forward(FloatTensor input);
};


#endif //DBN_BINARIZATIONOP_H
