//
// Created by jiangpq on 17-10-9.
//

#ifndef DBN_FLOATENOP_H
#define DBN_FLOATENOP_H


#include "../tensor/FloatTensor.h"
#include "../tensor/BinaryTensor8.h"
#include "../tensor/BinaryTensor16.h"

class FloatenOp {
public:
    FloatTensor *forward(BinaryTensor8 *input);

    FloatTensor *forward(BinaryTensor16 *input);
};


#endif //DBN_FLOATENOP_H
