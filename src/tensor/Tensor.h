//
// Created by jiangpq on 17-10-6.
//

#ifndef DBN_BASE_TENSOR_H
#define DBN_BASE_TENSOR_H


struct Tensor {
private:

    long int n_dimension;
    long int * dimensions;
public:
    Tensor(long n_dimension, const long *dimensions);
    virtual ~Tensor() = 0;
    long get_ndimension();
    long * get_dimensions();
    long get_length();

};


#endif //DBN_BASE_TENSOR_H
