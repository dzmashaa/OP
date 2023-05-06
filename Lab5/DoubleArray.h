//
// Created by я on 06.05.2023.
//

#ifndef LAB5_3_0_DOUBLEARRAY_H
#define LAB5_3_0_DOUBLEARRAY_H
#include "TArray.h"

class DoubleArray: public TArray{
protected:
double * arr;
public:
DoubleArray();
void fill_array() override;
void show_array() override;
void increase_elements(int) override;
void reduce_elements(int) override;
double find_arithmetic_mean() override;
~DoubleArray() override;
};


#endif //LAB5_3_0_DOUBLEARRAY_H
