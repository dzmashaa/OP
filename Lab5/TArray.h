//
// Created by я on 06.05.2023.
//

#ifndef LAB5_3_0_TARRAY_H
#define LAB5_3_0_TARRAY_H


class TArray {
protected:
    int size;
public:
    explicit TArray(int num): size(num){};
    virtual void fill_array() = 0;
    virtual void increase_elements(int) = 0;
    virtual void reduce_elements(int) = 0;
    virtual double find_arithmetic_mean() = 0;
    virtual void show_array() = 0;
    virtual ~TArray() = default;
};


#endif //LAB5_3_0_TARRAY_H
