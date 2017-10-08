//
// Created by jiangpq on 17-10-6.
//

#ifndef DBN_BASE_TENSOR_H
#define DBN_BASE_TENSOR_H


class BaseTensor {
private:

    long int n_dimension;
    long int * dimensions;
public:
    BaseTensor(long n_dimension, const long *dimensions);
    virtual ~BaseTensor() = 0;
    long int get_ndimension();
    long int * get_dimensions();

};


#endif //DBN_BASE_TENSOR_H
