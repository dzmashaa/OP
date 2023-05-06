#ifndef LAB5_3_0_INTARRAY_H
#define LAB5_3_0_INTARRAY_H
#include "TArray.h"

class IntArray: public TArray{
protected:
    int* arr;
public:
    IntArray();
    void fill_array() override;
    void show_array() override;
    void increase_elements(int) override;
    void reduce_elements(int) override;
    double find_arithmetic_mean() override;
    ~IntArray() override;
};


#endif //LAB5_3_0_INTARRAY_H
