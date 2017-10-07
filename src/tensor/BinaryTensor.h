//
// Created by jiangpq on 17-10-7.
//

#ifndef DBN_BINARYTENSOR_H
#define DBN_BINARYTENSOR_H


#include "BaseTensor.h"

class BinaryTensor: public BaseTensor {
private:
    long int last_dim_len;
public:
    BinaryTensor(long n_dimension, long *dimensions);
    long int get_actual_last_dim_len();

};


#endif //DBN_BINARYTENSOR_H
